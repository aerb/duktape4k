package ca.aerb.duktape4k.generator

class Tokenizer(private val text: String) {

  private var index: Int = 0

  private fun curr(): Char? =
    if (index >= text.length) null
    else text[index]

  private fun advance(): Char? {
    index++
    return curr()
  }

  private fun skipWhitespace() {
    while (curr()?.isWhitespace() == true) {
      advance()
    }
  }

  private fun collectWhile(predicate: (Char) -> Boolean): String {
    return buildString {
      var curr = curr()
      while (curr != null && predicate(curr)) {
        append(curr)
        curr = advance()
      }
    }
  }

  fun next(): Token {
    skipWhitespace()
    val curr = curr() ?: return Token.EOF
    if (curr.isNameCharacter()) {
      return Token.Name(collectWhile { it.isNameCharacter() })
    }
    if (curr == '.') {
      val ellipsis = collectWhile { it == '.' }
      check(ellipsis.length == 3) { "Unexpected $ellipsis" }
      return Token.Ellipsis
    }
    val singleToken = when (curr) {
      '(' -> Token.OpenParen
      ')' -> Token.CloseParen
      '*' -> Token.Pointer
      ',' -> Token.Comma
      ';' -> Token.EOL
      else -> null
    }
    if (singleToken != null) {
      advance()
      return singleToken
    }

    throw UnsupportedOperationException("Dont know what to do with $curr")
  }

  private fun Char.isNameCharacter(): Boolean = isLetterOrDigit() || this == '_'

  sealed class Token {
    data class Name(val value: String) : Token()
    object OpenParen : Token()
    object CloseParen : Token()
    object Pointer : Token()
    object Comma : Token()
    object Ellipsis : Token()
    object EOL : Token()
    object EOF : Token()
  }
}
