#include <jni.h>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
#include <stdlib.h>

#include <android/log.h>

using namespace std;
stack<string> operationsStack;
stack<double> numbersStack;
int arraySize = 0;

extern "C" {


void doOperation() {

    string oString = operationsStack.top();
    operationsStack.pop();

    double a = numbersStack.top();
    numbersStack.pop();
    double b = numbersStack.top();
    numbersStack.pop();

    if (oString == "x") {
        numbersStack.push(a * b);
    }
    else if (oString == "/") {
        numbersStack.push(b/a);
    }
    else if (oString == "+") {
        numbersStack.push(a + b);
    }
    else {
        numbersStack.push(b-a);
    }

}

double calcExpression(string calcArray[]) {

    for (int i = 0; i < arraySize; i++) {
        string chr = calcArray[i];
        if (chr == "(") {
        }
        else if (chr == "+" || chr == "x" || chr == "-" || chr == "/") {
            operationsStack.push(chr);
        }
        else if (chr == ")") {
            doOperation();
        }
        else {
            numbersStack.push(atof(chr.c_str()));
        }
    }
    doOperation();

    double result = numbersStack.top();
    numbersStack.pop();
    return result;
}

JNIEXPORT jstring JNICALL
Java_com_x10host_dhanushpatel_nativecalc_MainActivity_calcPrint
        (JNIEnv *env, jobject jot, jobjectArray calcArray, jint aSize) {

    arraySize = aSize;

    string cppArray[arraySize];
    for (int i = 0; i < arraySize; i++) {
        jstring string = (jstring) ((env)->GetObjectArrayElement(calcArray, i));
        const char *rawString = env->GetStringUTFChars(string, 0);
        cppArray[i] = rawString;
    }
    ostringstream oss;
    oss << calcExpression(cppArray);

    return env->NewStringUTF(oss.str().c_str());


}

JNIEXPORT void JNICALL
Java_com_x10host_dhanushpatel_nativecalc_MainActivity_calcCClear(JNIEnv *env) {
    while (!operationsStack.empty()) {
        operationsStack.pop();
    }
    while (!numbersStack.empty()) {
        numbersStack.pop();
    }
}

}

