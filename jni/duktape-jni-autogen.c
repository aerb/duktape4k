#include <jni.h>
#include "duktape/duktape.h"

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_debuggerCooperate(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_debugger_cooperate(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_debuggerDetach(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_debugger_detach(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_debuggerPause(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_debugger_pause(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_destroyHeap(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_destroy_heap(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_dumpFunction(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_dump_function(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_dupTop(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_dup_top(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_eval(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_eval(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_evalNoresult(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_eval_noresult(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_evalString(
  JNIEnv *env,
  jlong context_ptr,
  jstring src
) {
  duk_eval_string(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, src, NULL)
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_evalStringNoresult(
  JNIEnv *env,
  jlong context_ptr,
  jstring src
) {
  duk_eval_string_noresult(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, src, NULL)
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_fatal(
  JNIEnv *env,
  jlong context_ptr,
  jstring err_msg
) {
  int result = duk_fatal(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, err_msg, NULL)
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getCurrentMagic(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_get_current_magic(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getGlobalLiteral(
  JNIEnv *env,
  jlong context_ptr,
  jstring key_literal
) {
  int result = duk_get_global_literal(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, key_literal, NULL)
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getGlobalString(
  JNIEnv *env,
  jlong context_ptr,
  jstring key
) {
  int result = duk_get_global_string(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, key, NULL)
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getTop(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_get_top(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getTopIndex(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_get_top_index(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isConstructorCall(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_is_constructor_call(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isStrictCall(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_is_strict_call(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_loadFunction(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_load_function(
    (duk_context*) context_ptr
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_peval(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_peval(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pevalNoresult(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_peval_noresult(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pevalString(
  JNIEnv *env,
  jlong context_ptr,
  jstring src
) {
  int result = duk_peval_string(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, src, NULL)
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pevalStringNoresult(
  JNIEnv *env,
  jlong context_ptr,
  jstring src
) {
  int result = duk_peval_string_noresult(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, src, NULL)
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pop(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_pop(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pop2(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_pop_2(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pop3(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_pop_3(
    (duk_context*) context_ptr
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushArray(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_push_array(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushBareArray(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_push_bare_array(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushBareObject(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_push_bare_object(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushContextDump(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_context_dump(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushCurrentFunction(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_current_function(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushCurrentThread(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_current_thread(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushExternalBuffer(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_external_buffer(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushFalse(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_false(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushGlobalObject(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_global_object(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushGlobalStash(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_global_stash(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushHeapStash(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_heap_stash(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushNan(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_nan(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushNewTarget(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_new_target(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushNull(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_null(
    (duk_context*) context_ptr
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushObject(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_push_object(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushThis(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_this(
    (duk_context*) context_ptr
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushThread(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_push_thread(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushThreadNewGlobalenv(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_push_thread_new_globalenv(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushThreadStash(
  JNIEnv *env,
  jlong context_ptr,
  jlong target_ctx
) {
  duk_push_thread_stash(
    (duk_context*) context_ptr,
    (duk_context*) target_ctx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushTrue(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_true(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushUndefined(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_push_undefined(
    (duk_context*) context_ptr
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_putGlobalLiteral(
  JNIEnv *env,
  jlong context_ptr,
  jstring key_literal
) {
  int result = duk_put_global_literal(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, key_literal, NULL)
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_putGlobalString(
  JNIEnv *env,
  jlong context_ptr,
  jstring key
) {
  int result = duk_put_global_string(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, key, NULL)
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_requireConstructorCall(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_require_constructor_call(
    (duk_context*) context_ptr
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_requireTopIndex(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_require_top_index(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_setGlobalObject(
  JNIEnv *env,
  jlong context_ptr
) {
  duk_set_global_object(
    (duk_context*) context_ptr
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_throw(
  JNIEnv *env,
  jlong context_ptr
) {
  int result = duk_throw(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

