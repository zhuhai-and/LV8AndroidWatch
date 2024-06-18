#include <iostream>
#include <lvgl.h>
#include <lv_demos.h>
#include <jni.h>
#include <thread>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include "LVApp.h"
#include "LVHelper.h"


#define J_FUN(r, x) JNIEXPORT r JNICALL Java_com_lvgl_watch_demo_LVApp_##x

#ifdef __cplusplus
extern "C" {
#endif

using namespace std;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = nullptr;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    LOGD("JNI_OnLoad()");
    return JNI_VERSION_1_4;
}

J_FUN(jlong, nCreate)(JNIEnv *env, jclass clazz) {
    return (jlong) new LVApp();
}

J_FUN(jlong, nSetApp)(JNIEnv *env, jclass clazz, jlong id, jstring _name) {
    auto *name = env->GetStringUTFChars(_name, nullptr);
    auto *p = (LVApp *) id;
    p->setApp(name);
    env->ReleaseStringUTFChars(_name, name);
    return 0;
}

J_FUN(jlong, nStart)(JNIEnv *env, jclass clazz, jlong id, jobject surface) {
    auto *p = (LVApp *) id;
    ANativeWindow *window = ANativeWindow_fromSurface(env, surface);
    p->start(window);
    return 0;
}

J_FUN(jlong, nOnTouch)(JNIEnv *env, jclass clazz, jlong id, jint touch, jint x, jint y) {
    auto *p = (LVApp *) id;
    p->onTouch(touch, x, y);
    return 0;
}

J_FUN(jlong, nStop)(JNIEnv *env, jclass clazz, jlong id) {
    auto *p = (LVApp *) id;
    p->stop();
    return 0;
}

J_FUN(jlong, nDestroy)(JNIEnv *env, jclass clazz, jlong id) {
    auto *p = (LVApp *) id;
    delete p;
    return 0;
}

#ifdef __cplusplus
}
#endif
