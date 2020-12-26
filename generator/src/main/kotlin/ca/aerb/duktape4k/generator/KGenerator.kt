package ca.aerb.duktape4k.generator

object KGenerator {
  //private external fun evalString(contextPointer: Long, source: String)
  fun generate(functions: List<KotlinImplementation>) {
    val externalFunctions = functions.map { fn ->
      buildString {
        append("private external fun ${fn.name}(")
        appendLine()
        fn.args.forEachIndexed { index, arg ->
          append("  ").append(arg.name).append(": ").append(arg.type)
          if (index < fn.args.lastIndex) {
            append(",")
          }
          appendLine()
        }
        append(")")
        if (fn.returnType != "Unit") {
          append(": ").append(fn.returnType)
        }
        appendLine()
      }
    }
    externalFunctions.forEach { println(it) }

    val kFuns = functions.filter { it.args.first().name == "contextPtr" }.map { fn ->
      buildString {
        append("fun ").append(fn.name).append("(")
        appendLine()
        val args = fn.args.drop(1)
        args.forEachIndexed { index, arg ->
          append("  ").append(arg.name).append(": ").append(arg.type)
          if (index < fn.args.lastIndex) {
            append(",")
          }
          appendLine()
        }
        append(")")
        if (fn.returnType != "Unit") {
          append(": ").append(fn.returnType)
        }
        append(" {")
        appendLine()
        if (fn.returnType != "Unit") {
          append("  return ")
        } else {
          append("  ")
        }
        append(fn.name).append("(").append("pointer")
        args.forEach { append(", ").append(it.name) }
        append(")")

        appendLine()
        append("}")
        appendLine()
      }
    }

    kFuns.forEach { println(it) }
  }
}
