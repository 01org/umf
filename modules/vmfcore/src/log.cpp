// Copyright (C) 2013, Intel Corporation, all rights reserved.

#include <sstream>
#include <fstream>
#include <stdarg.h>
#include <iostream>
#include "vmf/log.hpp"

using namespace std;

namespace vmf
{
string Log::logFile = "";
bool Log::writeToFile = false;
LogLevel Log::verbosityLevel = LOG_INFO;

void Log::log(LogLevel level, const string &_msg, const string &func, const string &file, int line, ...)
{
    if (level < verbosityLevel)
    {
        return;
    }
    stringstream msgStream;
    switch (level)
    {
    case LOG_INFO:
        msgStream << "INFO:";
        break;
    case LOG_WARNING:
        msgStream << "WARNING:";
        break;
    case LOG_ERROR:
        msgStream << "ERROR:";
        break;
    default:
        msgStream << "UNKNOWN:";
    }

    string msg = _msg;
    size_t start_pos = 0;
    while((start_pos = msg.find("%", start_pos)) != std::string::npos) {
        size_t end_pos = start_pos + msg.length();
        msg.replace(start_pos, end_pos, string("%%"));
        start_pos += 2;
    }

    va_list args;
    va_start(args, line);
#if defined WIN32 || defined _WIN32 || defined WINCE || defined MINGW32
    int len = _vscprintf(msg.c_str(), args) + 1; 
#else
    int len = vsnprintf(NULL, 0, msg.c_str(), args) + 1; 
#endif
    va_end(args);
    va_list args1;
    va_start(args1, line);
    char* message = new char[len];
#if defined WIN32 || defined _WIN32 || defined WINCE || defined MINGW32
    vsnprintf_s(message, len, _TRUNCATE, msg.c_str(), args1);
#else
    vsnprintf(message, len, msg.c_str(), args1);
#endif
    va_end(args1);

    msgStream << " " << message << " in " << func << " " << file << ":" << line <<"\n";
    delete[] message;

    if (writeToFile)
    {
        writeMessageToFile(msgStream.str());
    }
    else
    {
        writeMessageToConsole(msgStream.str());
    }
}

void Log::logToFile(const string &file)
{
    writeToFile = true;
    logFile = file;
}

void Log::logToConsole()
{
    logFile = "";
    writeToFile = false;
}

void Log::writeMessageToConsole(const string &msg)
{
    cout << msg << endl;
}

void Log::writeMessageToFile(const string &msg)
{
    ofstream file(logFile, ios_base::app);
    file << msg;
    file.close();
}

void Log::setVerbosityLevel(LogLevel level)
{
    verbosityLevel = level;
}

LogLevel Log::getVerbosityLevel()
{
    return verbosityLevel;
}
}
