package ca.aerb.duktape4k.generator

import ca.aerb.duktape4k.generator.Tokenizer.Token
import java.lang.IllegalStateException

class Parser(private val tokenizer: Tokenizer) {

  private var curr: Token = tokenizer.next()

  private fun advance(): Token {
    curr = tokenizer.next()
    return curr
  }

  private inline fun <reified T : Token> currAs(): T {
    val curr = this.curr
    if (curr is T) {
      return curr
    } else {
      throw IllegalStateException("Expected ${T::class.java} but got ${curr::class.java}")
    }
  }

  fun parseAll(): List<CFunction> {
    val fns = ArrayList<CFunction>()
    while (curr !is Token.EOF) {
      fns += parse()!!
    }
    return fns
  }

  private fun skipRestOfLine() {
    while (curr !is Token.EOL) {
      advance()
    }
    advance()
  }

  private fun parse(): CFunction? {
    when (curr) {
      is Token.EOF -> {
        return null
      }
      is Token.Name -> {
        val ret = readType()
        val name =  currAs<Token.Name>().value
        advance()

        currAs<Token.OpenParen>()
        advance()

        val args = readArgs()
        currAs<Token.EOL>()
        advance()
        return CFunction(name, ret, args)
      }
      else -> throw UnsupportedOperationException("Don't know how to handle $curr")
    }
  }

  private fun readArgs(): List<Arg> {
    val args = ArrayList<Arg>()
    while (true) {
      if (curr is Token.CloseParen) {
        advance()
        return args
      }
      if (curr is Token.Ellipsis) {
        args += Arg("varargs", Type("*"))
        advance()
        continue
      }
      val type = readType()
      var name = ""
      if (curr is Token.Name) {
        name = currAs<Token.Name>().value
        advance()
      }
      args += Arg(name, type)
      if (curr is Token.Comma) {
        advance()
      }
    }
  }

  private fun readType(): Type {
    var curr = currAs<Token.Name>()
    val keywords = HashSet<String>()
    while (curr.value in TypeKeywords) {
      keywords += curr.value
      curr = advance() as Token.Name
    }
    val name = curr.value
    var isPointer = false
    val next = advance()
    if (next is Token.Pointer) {
      isPointer = true
      advance()
    }
    return Type(
      name = name,
      keywords = keywords,
      pointer =  isPointer
    )
  }

  companion object {
    val TypeKeywords = setOf("unsigned", "const")
  }
}
