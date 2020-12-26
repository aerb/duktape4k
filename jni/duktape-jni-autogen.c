#include <jni.h>
#include "duktape/duktape.h"
JNIEXPORT void JNICALL Java_aerb_foo_DukContext_base64Decode(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_base64_decode(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_base64Encode(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  const char *result = duk_base64_encode(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_bufferToString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  const char *result = duk_buffer_to_string(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_call(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint nargs
) {
  duk_call(
    (duk_context*) context_ptr,
    (int) nargs
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_callMethod(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint nargs
) {
  duk_call_method(
    (duk_context*) context_ptr,
    (int) nargs
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_callProp(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jint nargs
) {
  duk_call_prop(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (int) nargs
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_cborDecode(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jint decode_flags
) {
  duk_cbor_decode(
    (duk_context*) context_ptr,
    (int) idx,
    (unsigned int) decode_flags
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_cborEncode(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jint encode_flags
) {
  duk_cbor_encode(
    (duk_context*) context_ptr,
    (int) idx,
    (unsigned int) encode_flags
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_checkStack(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint extra
) {
  int result = duk_check_stack(
    (duk_context*) context_ptr,
    (int) extra
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_checkStackTop(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint top
) {
  int result = duk_check_stack_top(
    (duk_context*) context_ptr,
    (int) top
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_checkType(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jint type
) {
  int result = duk_check_type(
    (duk_context*) context_ptr,
    (int) idx,
    (int) type
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_checkTypeMask(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jint mask
) {
  int result = duk_check_type_mask(
    (duk_context*) context_ptr,
    (int) idx,
    (unsigned int) mask
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_compact(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx
) {
  duk_compact(
    (duk_context*) context_ptr,
    (int) obj_idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_compile(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint flags
) {
  duk_compile(
    (duk_context*) context_ptr,
    (unsigned int) flags
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_compileString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint flags,
  jstring src
) {
  duk_compile_string(
    (duk_context*) context_ptr,
    (unsigned int) flags,
    (*env)->GetStringUTFChars(env, src, NULL)
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_compileStringFilename(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint flags,
  jstring src
) {
  duk_compile_string_filename(
    (duk_context*) context_ptr,
    (unsigned int) flags,
    (*env)->GetStringUTFChars(env, src, NULL)
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_concat(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint count
) {
  duk_concat(
    (duk_context*) context_ptr,
    (int) count
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_copy(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint from_idx,
  jint to_idx
) {
  duk_copy(
    (duk_context*) context_ptr,
    (int) from_idx,
    (int) to_idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_debuggerCooperate(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_debugger_cooperate(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_debuggerDetach(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_debugger_detach(
    (duk_context*) context_ptr
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_debuggerNotify(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint nvalues
) {
  int result = duk_debugger_notify(
    (duk_context*) context_ptr,
    (int) nvalues
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_debuggerPause(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_debugger_pause(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_defProp(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jint flags
) {
  duk_def_prop(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (unsigned int) flags
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_delProp(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx
) {
  int result = duk_del_prop(
    (duk_context*) context_ptr,
    (int) obj_idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_delPropIndex(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jint arr_idx
) {
  int result = duk_del_prop_index(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (unsigned int) arr_idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_delPropLiteral(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jstring key_literal
) {
  int result = duk_del_prop_literal(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (*env)->GetStringUTFChars(env, key_literal, NULL)
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_delPropString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jstring key
) {
  int result = duk_del_prop_string(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (*env)->GetStringUTFChars(env, key, NULL)
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_destroyHeap(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_destroy_heap(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_dumpFunction(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_dump_function(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_dup(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint from_idx
) {
  duk_dup(
    (duk_context*) context_ptr,
    (int) from_idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_dupTop(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_dup_top(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_enum(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jint enum_flags
) {
  duk_enum(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (unsigned int) enum_flags
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_equals(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx1,
  jint idx2
) {
  int result = duk_equals(
    (duk_context*) context_ptr,
    (int) idx1,
    (int) idx2
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_eval(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_eval(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_evalNoresult(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_eval_noresult(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_evalString(
  JNIEnv *env,
  jobject obj,
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
  jobject obj,
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
  jobject obj,
  jlong context_ptr,
  jstring err_msg
) {
  int result = duk_fatal(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, err_msg, NULL)
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_freeze(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx
) {
  duk_freeze(
    (duk_context*) context_ptr,
    (int) obj_idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_gc(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint flags
) {
  duk_gc(
    (duk_context*) context_ptr,
    (unsigned int) flags
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getBoolean(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_get_boolean(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getBooleanDefault(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jint def_value
) {
  int result = duk_get_boolean_default(
    (duk_context*) context_ptr,
    (int) idx,
    (int) def_value
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getCurrentMagic(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_get_current_magic(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getErrorCode(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_get_error_code(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_getFinalizer(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_get_finalizer(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getGlobalLiteral(
  JNIEnv *env,
  jobject obj,
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
  jobject obj,
  jlong context_ptr,
  jstring key
) {
  int result = duk_get_global_string(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, key, NULL)
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getInt(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_get_int(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getIntDefault(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jint def_value
) {
  int result = duk_get_int_default(
    (duk_context*) context_ptr,
    (int) idx,
    (int) def_value
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getMagic(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_get_magic(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getProp(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx
) {
  int result = duk_get_prop(
    (duk_context*) context_ptr,
    (int) obj_idx
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_getPropDesc(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jint flags
) {
  duk_get_prop_desc(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (unsigned int) flags
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getPropIndex(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jint arr_idx
) {
  int result = duk_get_prop_index(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (unsigned int) arr_idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getPropString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jstring key
) {
  int result = duk_get_prop_string(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (*env)->GetStringUTFChars(env, key, NULL)
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_getPrototype(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_get_prototype(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_getString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  const char *result = duk_get_string(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_getStringDefault(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jstring def_value
) {
  const char *result = duk_get_string_default(
    (duk_context*) context_ptr,
    (int) idx,
    (*env)->GetStringUTFChars(env, def_value, NULL)
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getTop(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_get_top(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getTopIndex(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_get_top_index(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getType(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_get_type(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getTypeMask(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  unsigned int result = duk_get_type_mask(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getUint(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  unsigned int result = duk_get_uint(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_getUintDefault(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jint def_value
) {
  unsigned int result = duk_get_uint_default(
    (duk_context*) context_ptr,
    (int) idx,
    (unsigned int) def_value
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_hasProp(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx
) {
  int result = duk_has_prop(
    (duk_context*) context_ptr,
    (int) obj_idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_hasPropIndex(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jint arr_idx
) {
  int result = duk_has_prop_index(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (unsigned int) arr_idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_hasPropLiteral(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jstring key_literal
) {
  int result = duk_has_prop_literal(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (*env)->GetStringUTFChars(env, key_literal, NULL)
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_hasPropString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jstring key
) {
  int result = duk_has_prop_string(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (*env)->GetStringUTFChars(env, key, NULL)
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_hexDecode(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_hex_decode(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_hexEncode(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  const char *result = duk_hex_encode(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_insert(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint to_idx
) {
  duk_insert(
    (duk_context*) context_ptr,
    (int) to_idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_inspectCallstackEntry(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint level
) {
  duk_inspect_callstack_entry(
    (duk_context*) context_ptr,
    (int) level
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_inspectValue(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_inspect_value(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_instanceof(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx1,
  jint idx2
) {
  int result = duk_instanceof(
    (duk_context*) context_ptr,
    (int) idx1,
    (int) idx2
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isArray(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_array(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isBoolean(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_boolean(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isBoundFunction(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_bound_function(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isBuffer(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_buffer(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isBufferData(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_buffer_data(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isCFunction(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_c_function(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isCallable(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_callable(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isConstructable(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_constructable(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isConstructorCall(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_is_constructor_call(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isDynamicBuffer(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_dynamic_buffer(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isEcmascriptFunction(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_ecmascript_function(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isError(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_error(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isEvalError(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_eval_error(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isFixedBuffer(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_fixed_buffer(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isFunction(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_function(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isLightfunc(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_lightfunc(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isNan(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_nan(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isNull(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_null(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isNullOrUndefined(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_null_or_undefined(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isNumber(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_number(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isObject(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_object(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isObjectCoercible(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_object_coercible(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isPointer(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_pointer(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isPrimitive(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_primitive(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isRangeError(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_range_error(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isReferenceError(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_reference_error(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isStrictCall(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_is_strict_call(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_string(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isSymbol(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_symbol(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isSyntaxError(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_syntax_error(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isThread(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_thread(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isTypeError(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_type_error(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isUndefined(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_undefined(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isUriError(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_uri_error(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_isValidIndex(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_is_valid_index(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_join(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint count
) {
  duk_join(
    (duk_context*) context_ptr,
    (int) count
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_jsonDecode(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_json_decode(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_jsonEncode(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  const char *result = duk_json_encode(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_loadFunction(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_load_function(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_new(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint nargs
) {
  duk_new(
    (duk_context*) context_ptr,
    (int) nargs
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_next(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint enum_idx,
  jint get_value
) {
  int result = duk_next(
    (duk_context*) context_ptr,
    (int) enum_idx,
    (int) get_value
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_normalizeIndex(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_normalize_index(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_optBoolean(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jint def_value
) {
  int result = duk_opt_boolean(
    (duk_context*) context_ptr,
    (int) idx,
    (int) def_value
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_optInt(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jint def_value
) {
  int result = duk_opt_int(
    (duk_context*) context_ptr,
    (int) idx,
    (int) def_value
  );
  return (jint) result;
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_optString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jstring def_ptr
) {
  const char *result = duk_opt_string(
    (duk_context*) context_ptr,
    (int) idx,
    (*env)->GetStringUTFChars(env, def_ptr, NULL)
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_optUint(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jint def_value
) {
  unsigned int result = duk_opt_uint(
    (duk_context*) context_ptr,
    (int) idx,
    (unsigned int) def_value
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pcall(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint nargs
) {
  int result = duk_pcall(
    (duk_context*) context_ptr,
    (int) nargs
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pcallMethod(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint nargs
) {
  int result = duk_pcall_method(
    (duk_context*) context_ptr,
    (int) nargs
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pcallProp(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jint nargs
) {
  int result = duk_pcall_prop(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (int) nargs
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pcompile(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint flags
) {
  int result = duk_pcompile(
    (duk_context*) context_ptr,
    (unsigned int) flags
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pcompileString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint flags,
  jstring src
) {
  int result = duk_pcompile_string(
    (duk_context*) context_ptr,
    (unsigned int) flags,
    (*env)->GetStringUTFChars(env, src, NULL)
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pcompileStringFilename(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint flags,
  jstring src
) {
  int result = duk_pcompile_string_filename(
    (duk_context*) context_ptr,
    (unsigned int) flags,
    (*env)->GetStringUTFChars(env, src, NULL)
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_peval(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_peval(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pevalNoresult(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_peval_noresult(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pevalString(
  JNIEnv *env,
  jobject obj,
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
  jobject obj,
  jlong context_ptr,
  jstring src
) {
  int result = duk_peval_string_noresult(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, src, NULL)
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pnew(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint nargs
) {
  int result = duk_pnew(
    (duk_context*) context_ptr,
    (int) nargs
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pop(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_pop(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pop2(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_pop_2(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pop3(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_pop_3(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_popN(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint count
) {
  duk_pop_n(
    (duk_context*) context_ptr,
    (int) count
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pull(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint from_idx
) {
  duk_pull(
    (duk_context*) context_ptr,
    (int) from_idx
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushArray(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_push_array(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushBareArray(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_push_bare_array(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushBareObject(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_push_bare_object(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushBoolean(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint val
) {
  duk_push_boolean(
    (duk_context*) context_ptr,
    (int) val
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushContextDump(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_push_context_dump(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushCurrentFunction(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_push_current_function(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushCurrentThread(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_push_current_thread(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushExternalBuffer(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_push_external_buffer(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushFalse(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_push_false(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushGlobalObject(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_push_global_object(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushGlobalStash(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_push_global_stash(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushHeapStash(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_push_heap_stash(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushInt(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint val
) {
  duk_push_int(
    (duk_context*) context_ptr,
    (int) val
  );
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_pushLiteral(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jstring str_literal
) {
  const char *result = duk_push_literal(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, str_literal, NULL)
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushNan(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_push_nan(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushNewTarget(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_push_new_target(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushNull(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_push_null(
    (duk_context*) context_ptr
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushObject(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_push_object(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushProxy(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint proxy_flags
) {
  int result = duk_push_proxy(
    (duk_context*) context_ptr,
    (unsigned int) proxy_flags
  );
  return (jint) result;
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_pushString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jstring str
) {
  const char *result = duk_push_string(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, str, NULL)
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushThis(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_push_this(
    (duk_context*) context_ptr
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushThread(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_push_thread(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_pushThreadNewGlobalenv(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_push_thread_new_globalenv(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushThreadStash(
  JNIEnv *env,
  jobject obj,
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
  jobject obj,
  jlong context_ptr
) {
  duk_push_true(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushUint(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint val
) {
  duk_push_uint(
    (duk_context*) context_ptr,
    (unsigned int) val
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_pushUndefined(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_push_undefined(
    (duk_context*) context_ptr
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_putGlobalLiteral(
  JNIEnv *env,
  jobject obj,
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
  jobject obj,
  jlong context_ptr,
  jstring key
) {
  int result = duk_put_global_string(
    (duk_context*) context_ptr,
    (*env)->GetStringUTFChars(env, key, NULL)
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_putProp(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx
) {
  int result = duk_put_prop(
    (duk_context*) context_ptr,
    (int) obj_idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_putPropIndex(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jint arr_idx
) {
  int result = duk_put_prop_index(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (unsigned int) arr_idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_putPropLiteral(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jstring key_literal
) {
  int result = duk_put_prop_literal(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (*env)->GetStringUTFChars(env, key_literal, NULL)
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_putPropString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx,
  jstring key
) {
  int result = duk_put_prop_string(
    (duk_context*) context_ptr,
    (int) obj_idx,
    (*env)->GetStringUTFChars(env, key, NULL)
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_remove(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_remove(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_replace(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint to_idx
) {
  duk_replace(
    (duk_context*) context_ptr,
    (int) to_idx
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_requireBoolean(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_require_boolean(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_requireCallable(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_require_callable(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_requireConstructable(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_require_constructable(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_requireConstructorCall(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_require_constructor_call(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_requireFunction(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_require_function(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_requireInt(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_require_int(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_requireNormalizeIndex(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_require_normalize_index(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_requireNull(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_require_null(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_requireObject(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_require_object(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_requireObjectCoercible(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_require_object_coercible(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_requireStack(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint extra
) {
  duk_require_stack(
    (duk_context*) context_ptr,
    (int) extra
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_requireStackTop(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint top
) {
  duk_require_stack_top(
    (duk_context*) context_ptr,
    (int) top
  );
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_requireString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  const char *result = duk_require_string(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_requireTopIndex(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_require_top_index(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_requireTypeMask(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jint mask
) {
  duk_require_type_mask(
    (duk_context*) context_ptr,
    (int) idx,
    (unsigned int) mask
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_requireUint(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  unsigned int result = duk_require_uint(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_requireUndefined(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_require_undefined(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_requireValidIndex(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_require_valid_index(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_safeToStacktrace(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  const char *result = duk_safe_to_stacktrace(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_safeToString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  const char *result = duk_safe_to_string(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_samevalue(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx1,
  jint idx2
) {
  int result = duk_samevalue(
    (duk_context*) context_ptr,
    (int) idx1,
    (int) idx2
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_seal(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint obj_idx
) {
  duk_seal(
    (duk_context*) context_ptr,
    (int) obj_idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_setFinalizer(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_set_finalizer(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_setGlobalObject(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  duk_set_global_object(
    (duk_context*) context_ptr
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_setMagic(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jint magic
) {
  duk_set_magic(
    (duk_context*) context_ptr,
    (int) idx,
    (int) magic
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_setPrototype(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_set_prototype(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_setTop(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_set_top(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_strictEquals(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx1,
  jint idx2
) {
  int result = duk_strict_equals(
    (duk_context*) context_ptr,
    (int) idx1,
    (int) idx2
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_swap(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx1,
  jint idx2
) {
  duk_swap(
    (duk_context*) context_ptr,
    (int) idx1,
    (int) idx2
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_swapTop(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_swap_top(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_throw(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr
) {
  int result = duk_throw(
    (duk_context*) context_ptr
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_toBoolean(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  int result = duk_to_boolean(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_toInt(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint index
) {
  int result = duk_to_int(
    (duk_context*) context_ptr,
    (int) index
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_toNull(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_to_null(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_toObject(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_to_object(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_toPrimitive(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx,
  jint hint
) {
  duk_to_primitive(
    (duk_context*) context_ptr,
    (int) idx,
    (int) hint
  );
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_toStacktrace(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  const char *result = duk_to_stacktrace(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT jstring JNICALL Java_aerb_foo_DukContext_toString(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  const char *result = duk_to_string(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT jint JNICALL Java_aerb_foo_DukContext_toUint(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  unsigned int result = duk_to_uint(
    (duk_context*) context_ptr,
    (int) idx
  );
  return (jint) result;
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_toUndefined(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_to_undefined(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_trim(
  JNIEnv *env,
  jobject obj,
  jlong context_ptr,
  jint idx
) {
  duk_trim(
    (duk_context*) context_ptr,
    (int) idx
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_xcopyTop(
  JNIEnv *env,
  jobject obj,
  jlong to_ctx,
  jlong from_ctx,
  jint count
) {
  duk_xcopy_top(
    (duk_context*) to_ctx,
    (duk_context*) from_ctx,
    (int) count
  );
}

JNIEXPORT void JNICALL Java_aerb_foo_DukContext_xmoveTop(
  JNIEnv *env,
  jobject obj,
  jlong to_ctx,
  jlong from_ctx,
  jint count
) {
  duk_xmove_top(
    (duk_context*) to_ctx,
    (duk_context*) from_ctx,
    (int) count
  );
}

