package ca.aerb.duktape4k.generator

class KotlinImplementation(jniImplementation: JniImplementation) {
  val name = jniImplementation.camelCaseName.renameKeywords()

  // skip env & obj args
  val args = jniImplementation.jniFunctionHeader.args.drop(2).map {
    KArg(
      name = it.name.toCamelCase().renameKeywords(),
      type = it.type.toKotlinType()
    )
  }
  val returnType = jniImplementation.jniFunctionHeader.returnType.toKotlinType()

  private fun String.renameKeywords(): String =
    when (this) {
    "val" -> "value"
    "throw" -> "`throw`"
    else -> this
  }

  private fun Type.toKotlinType(): String {
    if (pointer) {
      return "Long"
    } else {
      return when (name) {
        "jint" -> "Int"
        "jlong" -> "Long"
        "jstring" -> "String"
        "void" -> "Unit"
        else -> throw IllegalArgumentException("Don't know how to handle $this")
      }
    }
  }
}




