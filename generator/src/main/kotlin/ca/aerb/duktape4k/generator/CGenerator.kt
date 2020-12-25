package ca.aerb.duktape4k.generator

import java.io.File

class CGenerator(private val functions: List<CFunction>) {

  fun generate() {
    val supported = functions.filter {
      it.returnType in SupportedReturn &&
        it.args.all { arg ->
          arg.type in SupportedArgs
        }
    }

    val declarations = supported.map { it.toTargets() }.map { target ->
      val jniFunction = target.jniFunctionHeader
      val apiFunction = target.apiFunction
      buildString {
        append("JNIEXPORT ")
        append(jniFunction.returnType.name)
        append(" JNICALL ")
        append(jniFunction.name).append("(")
        appendLine()
        jniFunction.args.forEachIndexed { i, arg ->
          append("  ").append(arg.type.name).append(" ")
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
          append("  ").append(apiFunction.returnType.name).append(" ")
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

  companion object {
    private val JniDir = File("../jni")
    private val AutogenFile = File(JniDir, "duktape-jni-autogen.c")

    private val SupportedReturn = listOf(
      Type("void"),
      Type("int"),
      Type("int", setOf("unsigned"))
    )

    private val SupportedArgs = listOf(
      Type("duk_context", pointer = true),
      Type("duk_uint_t"),
      Type("char", pointer = true),
      Type("char", pointer = true, keywords = setOf("const"))
    )
  }
}