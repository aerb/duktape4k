package aerb.foo

@Suppress("unused")
data class DukContext(private val pointer: Long) {

  private external fun evalString(contextPointer: Long, source: String)
  private external fun getInt(contextPointer: Long): Int
  private external fun pcompileString(contextPointer: Long, flags: Int, source: String): Int
  private external fun safeToString(contextPointer: Long, index: Int): String
  private external fun pcall(contextPointer: Long, numberOfArgs: Int): Int

  private external fun pushString(contextPointer: Long, value: String)
  private external fun pcompile(contextPointer: Long, flags: Int): Int

  fun evalString(source: String) {
    evalString(pointer, source)
  }

  fun getInt(): Int {
    return getInt(pointer)
  }

  fun pcompileString(flags: Int, source: String): Int {
    return pcompileString(pointer, flags, source)
  }

  fun safeToString(index: Int = -1): String {
    return safeToString(pointer, index)
  }

  fun pcall(numberOfArgs: Int): Int {
    return pcall(pointer, numberOfArgs)
  }

  fun pcompile(flags: Int = 0): Int {
    return pcompile(pointer, flags)
  }

  fun pushString(value: String) {
    return pushString(pointer, value)
  }

}
