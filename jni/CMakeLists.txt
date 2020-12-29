cmake_minimum_required(VERSION 3.17)
project(ducktape-jni C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Release)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

add_library(duktape-jni SHARED
        duktape-jni.c
        duktape-jni-autogen.c
        duktape/duktape.c
        duktape/duk_print_alert.c)