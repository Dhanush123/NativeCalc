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
    double total = bill + ((100 * tip)*bill);
    double perPerson = (total/numPeople);

    //to round accurately to 2 decimal places
    perPerson = (int)(perPerson*100+0.5f);
    perPerson = ((float)(perPerson))/100.0;

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
