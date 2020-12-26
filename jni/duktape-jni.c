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