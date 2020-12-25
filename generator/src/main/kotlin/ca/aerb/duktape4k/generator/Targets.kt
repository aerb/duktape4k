package ca.aerb.duktape4k.generator

import java.lang.IllegalArgumentException

class Targets(val apiFunction: CFunction) {

  private fun CFunction.jniName(): String {
    val camelCase: String =
      name.removePrefix("duk_").split("_")
        .mapIndexed { index, word -> if (index == 0) word else word.capitalize() }
        .joinToString(separator = "")

    return "Java_aerb_foo_DukContext_$camelCase"
  }

  private fun Arg.jniName(): String {
    if (type.name == "duk_context" && name == "ctx") {
      return "context_ptr"
    } else {
      return name
    }
  }

  val assignments = mutableListOf<Assignment>()
  val jniFunctionHeader: CFunction

  private fun Type.toJniType(): Type {
    return when (name) {
      "duk_context" -> {
        requirePointer()
        Type("jlong")
      }
      "int" -> Type("jint")
      "char" -> {
        requirePointer()
        Type("jstring")
      }
      "void" -> Type("void")
      else -> throw IllegalArgumentException("Dont know how to handle $this")
    }
  }

  init {
    val jniArgs = mutableListOf(Arg("env", Type("JNIEnv", pointer = true)))

    for (apiArg in apiFunction.args) {
      val jniType = apiArg.type.toJniType()

      val jniArg = Arg(
        name = apiArg.jniName(),
        type = jniType,
      )
      jniArgs += jniArg
      assignments += Assignment(to = apiArg, from = jniArg)
    }

    jniFunctionHeader = CFunction(
      name = apiFunction.jniName(),
      returnType = apiFunction.returnType.toJniType(),
      args = jniArgs
    )
  }
}


