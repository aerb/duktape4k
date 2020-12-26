package ca.aerb.duktape4k.generator

import java.io.File

object CGenerator {
  private val JniDir = File("../jni")
  private val AutogenFile = File(JniDir, "duktape-jni-autogen.c")

  fun generate(jniImplementations: List<JniImplementation>) {
    val declarations = jniImplementations.map { target ->
      val jniFunction = target.jniFunctionHeader
      val apiFunction = target.apiFunction
      buildString {
        append("JNIEXPORT ")
        append(jniFunction.returnType.nameWithKeywords())
        append(" JNICALL ")
        append(jniFunction.name).append("(")
        appendLine()
        jniFunction.args.forEachIndexed { i, arg ->
          append("  ").append(arg.type.nameWithKeywords()).append(" ")
          if (arg.type.pointer) {
            append("*")
          }
          append(arg.name)
          if (i < jniFunction.args.lastIndex) {
            append(",")
          }
          appendLine()
        }
        append(") {")
        appendLine()
        if (!apiFunction.returnType.noReturn) {
          append("  ").append(apiFunction.returnType.nameWithKeywords()).append(" ")
          if (apiFunction.returnType.pointer) {
            append("*")
          }
          append("result = ")
        } else {
          append("  ")
        }
        append(apiFunction.name).append("(")
        appendLine()
        target.assignments.forEachIndexed { i, assignment ->
          append("    ").append(
            CTypeConverter.convert(
              to = assignment.to.type,
              from = assignment.from.type,
              reference = assignment.from.name
            )
          )
          if (i < target.assignments.lastIndex) {
            append(",")
          }
          appendLine()
        }
        append("  );")
        appendLine()

        if (!apiFunction.returnType.noReturn) {
          append("  return ").append(
            CTypeConverter.convert(
              to = jniFunction.returnType,
              from = apiFunction.returnType,
              reference = "result"
            )
          ).append(";")
          appendLine()
        }
        append("}")
        appendLine()
      }
    }

    AutogenFile.writer().use { writer ->
      writer.appendLine("""
        #include <jni.h>
        #include "duktape/duktape.h"
      """.trimIndent())
      declarations.forEach {
        writer.appendLine(it)
      }
    }
  }
}