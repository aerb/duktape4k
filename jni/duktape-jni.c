#include "duktape/duktape.h"
#include "duktape/duk_print_alert.h"
#include "duktape-jni.h"

JNIEXPORT jlong JNICALL Java_aerb_foo_Test_createHeapDefault(
  JNIEnv *env
) {
  duk_context *ctx = duk_create_heap_default();
  duk_print_alert_init(ctx, 0);
  return (jlong) ctx;
}

//JNIEXPORT void JNICALL Java_aerb_foo_DukContext_evalString(
//  JNIEnv *env,
//  jobject obj,
//  jlong ptr,
//  jstring source
//) {
//  const char *chars = (*env)->GetStringUTFChars(env, source, NULL);
//  duk_eval_string((duk_context *) ptr, chars);
//}

//JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getInt(
//  JNIEnv *env,
//  jobject obj,
//  jlong ptr
//  ) {
//  return (jint) duk_get_int((duk_context *) ptr, -1);
//}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pcompileString(
  JNIEnv *env,
  jobject obj,
  jlong ptr,
  jint flags,
  jstring source
) {
  const char *chars = (*env)->GetStringUTFChars(env, source, NULL);
  return (jint) duk_pcompile_string((duk_context *) ptr, (duk_uint_t) flags, chars);
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_safeToString(
  JNIEnv *env,
  jobject obj,
  jlong ptr,
  jint index
) {
  const char *chars = duk_safe_to_string((duk_context *) ptr, (duk_uint_t) index);
  return (*env)->NewStringUTF(env, chars);
}

JNIEXPORT int JNICALL Java_aerb_foo_DukContext_pcall(
  JNIEnv *env,
  jobject obj,
  jlong ptr,
  jint nargs
) {
  return duk_pcall((duk_context *) ptr, (duk_idx_t) nargs);
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushString(
  JNIEnv *env,
  jobject obj,
  jlong ptr,
  jstring value
) {
  const char *chars = (*env)->GetStringUTFChars(env, value, NULL);
  duk_push_string((duk_context *) ptr, chars);
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pcompile(
  JNIEnv *env,
  jobject obj,
  jlong ptr,
  jint flags
) {
  return (jint) duk_pcompile((duk_context *) ptr, (duk_uint_t) flags);
}