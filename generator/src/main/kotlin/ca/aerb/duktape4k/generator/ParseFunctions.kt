package ca.aerb.duktape4k.generator

import java.io.File

fun main() {
  val fns = Parser(Tokenizer(File("functions.txt").readText())).parseAll()
  CGenerator(fns).generate()
}