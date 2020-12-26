package ca.aerb.duktape4k.generator

import java.io.File

fun main() {
  val fns = Parser(Tokenizer(File("functions.txt").readText())).parseAll()

  val supported = fns.filter {
    val filter = it.returnType in SupportedReturn &&
      it.args.all { arg ->
        arg.type in SupportedArgs
      }
    if (!filter) println("skipping ${it.name}")
    filter
  }

  println("conversion yes:${supported.size} / ${fns.size} ")

  val jniImplementations = supported.map { it.toJniImplementation() }
  //CGenerator.generate(jniImplementations)

  KGenerator.generate(jniImplementations.map { it.toKotlinImplementation() })
}

private val SupportedReturn = listOf(
  Type("void"),
  Type("int"),
  Type("int", setOf("unsigned")),
  Type("char", pointer = true),
  Type("char", pointer = true, keywords = setOf("const"))
)

private val SupportedArgs = listOf(
  Type("duk_context", pointer = true),
  Type("duk_uint_t"),
  Type("int"),
  Type("int", setOf("unsigned")),
  Type("char", pointer = true),
  Type("char", pointer = true, keywords = setOf("const"))
)