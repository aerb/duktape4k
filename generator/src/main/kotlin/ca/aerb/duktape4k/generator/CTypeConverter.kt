package ca.aerb.duktape4k.generator

object CTypeConverter {

  private fun cast(to: Type, reference: String): String = to.cast() + " " + reference

  fun convert(to: Type, reference: String, from: Type?): String {
    return when (to.name) {
      "jlong",
      "jint" -> cast(to, reference)
      "duk_context" -> {
        require(to.pointer)
        cast(to, reference)
      }
      "jstring" -> {
        when (from?.name) {
          "char" -> {
            require(from.pointer)
            "(*env)->NewStringUTF(env, $reference)"
          }
          else -> cast(to, reference)
        }
      }
      "int" -> {
        cast(to, reference)
      }
      "char" -> {
        require(to.pointer)
        when (from?.name) {
          "jstring" -> "(*env)->GetStringUTFChars(env, ${reference}, NULL)"
          else -> cast(to, reference)
        }
      }
      else -> throw IllegalStateException("Don't know how to translate type: $to")
    }
  }
}