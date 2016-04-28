#include <jni.h>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>

#include <android/log.h>

using namespace std;
stack<string> calcStack;

extern "C" {

int doOperation(double a,string s, double b) {
    double result = 0;
    if(s=="x"){
     result = a * b;
    }
    else if(s=="/"){
        result = a/b;
    }
    else if(s=="+"){
        result = a+b;
    }
    else{
        result = a - b;
        //s == -
    }
    return result;
}



JNIEXPORT void JNICALL
Java_com_x10host_dhanushpatel_nativecalc_MainActivity_ArrayAdd
        (JNIEnv *env, jobjectArray calcArray) {

    int size = env->GetArrayLength(calcArray);
    string cppArray[size];
    for (int i = 0; i < size; i++) {
        jstring string = (jstring) ((env)->GetObjectArrayElement(calcArray, i));
        const char *rawString = env->GetStringUTFChars(string, 0);
        cppArray[i]=rawString;
    }

    int cSize = cppArray->size();

    for (int j = cSize; j > 0; j--) {
        if(cppArray[j]=="x" || cppArray[j]=="/" || cppArray[j]=="+" || cppArray[j]=="-"){
            calcStack.push(cppArray[j]);
        }

    }
    for (int k = 0; k < cSize; k++) {
        if(calcStack.size()!=1) {
            if (isdigit(atof(cppArray[k].c_str()))) {
                //add the numbers to stack
                if (isdigit(atof(calcStack.top().c_str()))) {
                    double topDigit = atof(calcStack.top().c_str());
                    calcStack.pop();
                    string topOp = calcStack.top();
                    calcStack.pop();
                    double currentDigit = atof(cppArray[k].c_str());
                    double result = doOperation(topDigit, topOp, currentDigit);
                    ostringstream oss;
                    oss << result;
                    calcStack.push(oss.str());
                }
                else {
                    calcStack.push(cppArray[k]);
                }
            }
        }
    }
}


JNIEXPORT jstring JNICALL
Java_com_x10host_dhanushpatel_nativecalc_MainActivity_calcPrint
        (JNIEnv *env) {


    return env->NewStringUTF((const char *) calcStack.top().c_str());


}

}
