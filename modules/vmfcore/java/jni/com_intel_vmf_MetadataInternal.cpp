#include<string>
#include<vector>
#include <memory>
#include <stdexcept>
#include "vmf/metadatastream.hpp"
#include "../com_intel_vmf_MetadataInternal.h"
#include "throwJavaException.hpp"

using namespace vmf;

/*
 * Class:     com_intel_vmf_MetadataInternal
 * Method:    n_MetadataInternal
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_vmf_MetadataInternal_n_1MetadataInternal (JNIEnv *env, jclass, jlong mdDescAddr)
{
    std::shared_ptr<MetadataDesc>* mdDesc = (std::shared_ptr<MetadataDesc>*) mdDescAddr;
    std::shared_ptr<MetadataInternal>* p = new std::shared_ptr<MetadataInternal>(new MetadataInternal(*mdDesc));
    return (jlong)p;
}

/*
 * Class:     com_intel_vmf_MetadataInternal
 * Method:    n_MetadataInternalCopy
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_vmf_MetadataInternal_n_1MetadataInternalCopy (JNIEnv *env, jclass, jlong otherAddr)
{
    static const char method_name[] = "MetadataInternal::n_1MetadataInternalCopy";

    try
    {
        std::shared_ptr<MetadataInternal>* other = (std::shared_ptr<MetadataInternal>*) otherAddr;
        return (jlong) new std::shared_ptr <MetadataInternal>(new MetadataInternal ((**other)));
    }
    catch (const std::exception &e)
    {
        throwJavaException(env, &e, method_name);
    }
    catch (...)
    {
        throwJavaException(env, 0, method_name);
    }

    return 0;
}

/*
 * Class:     com_intel_vmf_MetadataInternal
 * Method:    n_MetadataInternalByMD
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_vmf_MetadataInternal_n_1MetadataInternalByMD (JNIEnv *env, jclass, jlong mdAddr)
{
    static const char method_name[] = "MetadataInternal::n_1MetadataInternalByMD";

    try
    {
        std::shared_ptr<Metadata>* md = (std::shared_ptr<Metadata>*) mdAddr;
        return (jlong) new std::shared_ptr <MetadataInternal>(new MetadataInternal((**md)));
    }
    catch (const std::exception &e)
    {
        throwJavaException(env, &e, method_name);
    }
    catch (...)
    {
        throwJavaException(env, 0, method_name);
    }

    return 0;
}

/*
 * Class:     com_intel_vmf_MetadataInternal
 * Method:    n_delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_intel_vmf_MetadataInternal_n_1delete (JNIEnv *env, jclass, jlong self)
{
    static const char method_name[] = "MetadataInternal::n_1delete";

    try
    {
        std::shared_ptr<MetadataInternal>* p = (std::shared_ptr<MetadataInternal>*) self;
        delete p;
    }
    catch (const std::exception &e)
    {
        throwJavaException(env, &e, method_name);
    }
    catch (...)
    {
        throwJavaException(env, 0, method_name);
    }
}
