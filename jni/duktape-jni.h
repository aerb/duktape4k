#include <jni.h>

JNIEXPORT jlong JNICALL Java_aerb_foo_Test_createHeapDefault(JNIEnv *env);
JNIEXPORT void JNICALL Java_aerb_foo_DukContext_evalString(JNIEnv* env, jobject obj, jlong ptr, jstring source);
JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getInt(JNIEnv* env, jobject obj, jlong ptr);

JNIEXPORT duk_int_t JNICALL Java_aerb_foo_DukContext_pcompileString(
  JNIEnv *env,
  jobject obj,
  jlong ptr,
  jint flags,
  jstring source
);

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_safeToString(
  JNIEnv *env,
  jobject obj,
  jlong ptr,
  jint index
);

JNIEXPORT int JNICALL Java_aerb_foo_DukContext_pcall(
  JNIEnv *env,
  jobject obj,
  jlong ptr,
  jint nargs
);

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushString(
  JNIEnv *env,
  jobject obj,
  jlong ptr,
  jstring value
);

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pcompile(
  JNIEnv *env,
  jobject obj,
  jlong ptr,
  jint flags
);