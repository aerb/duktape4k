package ca.aerb.duktape4k.generator

fun String.toCamelCase(): String {
  return split("_")
    .mapIndexed { index, word -> if (index == 0) word else word.capitalize() }
    .joinToString(separator = "")
}