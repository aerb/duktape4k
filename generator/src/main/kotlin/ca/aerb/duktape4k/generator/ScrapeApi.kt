package ca.aerb.duktape4k.generator

import org.jsoup.Jsoup
import java.io.File

fun main() {
  val functions = Jsoup.connect("https://duktape.org/api.html").get()
    .select(".api-call .api-part .sectiontitle")
    .asSequence()
    .map { it.parent().select("pre.c-code").first()?.attr("title")?.removePrefix("C99/C++11 (32-bit): ")?.trim() }
    .filter { !it.isNullOrBlank() }
    .joinToString(separator = "\n")
  println(functions)
  File("functions.txt").writeText(functions)
}