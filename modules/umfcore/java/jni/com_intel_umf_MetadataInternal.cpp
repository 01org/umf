#include<string>
#include<vector>
#include <memory>
#include <stdexcept>
#include "umf/metadatastream.hpp"
#include "throwJavaException.hpp"

extern "C" {

using namespace umf;

/*
 * Class:     com_intel_umf_MetadataInternal
 * Method:    n_delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_intel_umf_MetadataInternal_n_1delete(JNIEnv *env, jclass, jlong self);


JNIEXPORT void JNICALL Java_com_intel_umf_MetadataInternal_n_1delete (JNIEnv *env, jclass, jlong self)
{
    static const char method_name[] = "MetadataInternal::n_1delete";

    try
    {
        MetadataInternal* obj = (MetadataInternal*) self;

        if (obj == NULL)
            UMF_EXCEPTION (NullPointerException, "Metadata Internal is null pointer.");

        delete obj;
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


}
