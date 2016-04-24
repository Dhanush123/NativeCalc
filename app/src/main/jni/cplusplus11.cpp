#include <jni.h>

#include <android/log.h>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jdouble JNICALL
Java_com_x10host_dhanushpatel_nativecalc_MainActivity_tipCalc
        (JNIEnv *env, jobject obj, jint numPeople, jdouble bill, jdouble tip)
{
    double total = bill + ((tip/100.0)*bill);
    double perPerson = (total/((double)numPeople));


    __android_log_print(ANDROID_LOG_INFO, "sometag", "test int = %d", total);
    __android_log_print(ANDROID_LOG_INFO, "sometag2", "test int = %d",perPerson);

    if((perPerson*numPeople)<total){
        while((perPerson*numPeople)<total){
            perPerson = perPerson + 0.01;
        }
    }

    return perPerson;



#ifdef __cplusplus
}
#endif
}
