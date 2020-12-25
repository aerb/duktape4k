package ca.aerb.duktape4k.generator

data class CFunction(
  val name: String,
  val returnType: Type,
  val args: List<Arg>
) {

  fun toTargets(): Targets {
    return Targets(this)
  }
}

data class Type(
  val name: String,
  val keywords: Set<String> = emptySet(),
  val pointer: Boolean = false
) {
  val noReturn: Boolean = name == "void" && !pointer

  fun cast(): String = buildString {
    append("(")
    append(name)
    if (pointer) append("*")
    append(")")
  }

  fun requirePointer() {
    require(pointer)
  }
}

data class Arg(val name: String, val type: Type)

class Assignment(val to: Arg, val from: Arg)
