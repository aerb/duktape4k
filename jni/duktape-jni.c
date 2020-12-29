#include <jni.h>
#include <stdlib.h>
#include "duktape/duktape.h"
#include "duktape/duk_print_alert.h"

typedef struct {
  JNIEnv *env;
  jobject obj;
} java_context_object;

static void fatal_handler(void *udata, const char *msg) {
  fprintf(stderr, "FATAL ERROR: %s\n", (msg ? msg : ""));
  fflush(stderr);
  abort();
}

JNIEXPORT jlong JNICALL Java_aerb_foo_Test_createHeapDefault(
  JNIEnv *env
) {
  duk_context *ctx = duk_create_heap(NULL, NULL, NULL, NULL, fatal_handler);
  duk_print_alert_init(ctx, 0);
  return (jlong) ctx;
}


JNIEXPORT void JNICALL Java_aerb_foo_DukContext_setupContext(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_context *ctx = (duk_context *) context_ptr;

  java_context_object *inst = malloc(sizeof(java_context_object));
  inst->env = env;
  inst->obj = obj;

  duk_push_global_stash(ctx);
  duk_push_pointer(ctx, inst);
  duk_put_prop_string(ctx, -2, "JVM_CONTEXT_OBJECT");

  duk_pop(ctx);
}

java_context_object* get_stashed_jvm_object(duk_context *ctx) {
  duk_push_global_stash(ctx);
  duk_get_prop_string(ctx, -1, "JVM_CONTEXT_OBJECT");
  java_context_object *obj = duk_require_pointer(ctx, -1);
  duk_pop_2(ctx);
  return obj;
}

duk_ret_t delegate_to_jvm(duk_context *ctx) {
  printf("Native hello\n");

  java_context_object *jvm_obj = get_stashed_jvm_object(ctx);
  JNIEnv *env = jvm_obj->env;
  jobject obj = jvm_obj->obj;

  jclass cls = (*env)->FindClass(env, "aerb/foo/DukContext");
  jmethodID mid = (*env)->GetMethodID(env, cls, "invokedFromDuktape", "()I");
  return (duk_ret_t) (*env)->CallIntMethod(env, obj, mid);
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushJvmDelegateFunction(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  return duk_push_c_function((duk_context *) context_ptr, delegate_to_jvm, DUK_VARARGS);
}

