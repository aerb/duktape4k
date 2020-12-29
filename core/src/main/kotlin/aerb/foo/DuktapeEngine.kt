package aerb.foo

import java.io.Closeable
import java.lang.System.err

private const val DUK_HIDDEN_PROPERTY_PREFIX = "\\xff\\xff"
private const val DUK_FUNCTION_NAME = "${DUK_HIDDEN_PROPERTY_PREFIX}functionName"

private const val DUK_TYPE_NONE = 0 // no value, e.g. invalid index
private const val DUK_TYPE_UNDEFINED = 1 // ECMAScript undefined
private const val DUK_TYPE_NULL = 2 // ECMAScript null
private const val DUK_TYPE_BOOLEAN = 3 // ECMAScript boolean: 0 or 1
private const val DUK_TYPE_NUMBER = 4 // ECMAScript number: double
private const val DUK_TYPE_STRING = 5 // ECMAScript string: CESU-8 / extended UTF-8 encoded
private const val DUK_TYPE_OBJECT = 6 // ECMAScript object: includes objects, arrays, functions, threads
private const val DUK_TYPE_BUFFER = 7 // fixed or dynamic, garbage collected byte buffer
private const val DUK_TYPE_POINTER = 8 // raw void pointer
private const val DUK_TYPE_LIGHTFUNC = 9 // lightweight function pointer
private const val DUK_TYPE_MAX = 9

class DuktapeEngine : Closeable, DuktapeCallbackHandler {

  private val context = Test.newContext(this)
  private var closed: Boolean = false
  private val functions = HashMap<String, Function<*>>()

  init {
    registerGlobalFunction("hello_function", this::hello)
    registerGlobalFunction("hello_function_2", this::hello2)

    assertEmptyStack()

    evaluate("hello_function('hello', 42);")
    evaluate("hello_function_2();")
  }

  private fun hello(a: String, b: Int) {
    println("hello $a $b")
  }

  private fun hello2() {
    println("hello2")
  }

  fun registerGlobalFunction(name: String, function: Function<*>) {
    functions[name] = function
    preservingValueStack {
      pushGlobalObject()
      pushJvmDelegateFunction()
      pushString(name)
      putPropString(-2, DUK_FUNCTION_NAME)
      putPropString(-2, name)
    }
  }

  override fun handleDuktapeCall(): Int {
    val functionName = preservingValueStack {
      pushCurrentFunction()
      getPropString(-1, DUK_FUNCTION_NAME)
      getString(-1)
    }

    val function = functions[functionName] ?: error("Could not find $functionName")
    val sam = function.javaClass.declaredMethods.first()
    val args = ArrayList<Any?>()
    withContext {
      while (getTop() > 0) {
        args += when(val type = getType(-1)) {
          DUK_TYPE_STRING -> getString(-1)
          DUK_TYPE_NUMBER -> getInt(-1)
          else -> error("Don't know how to handle $type")
        }
        pop()
      }
    }

    try {
      sam.invoke(function, *args.reversed().toTypedArray())
    } catch (t: Throwable) {
      t.printStackTrace()
    }

    return 0
  }

  private fun <T> withContext(function: DukContext.() -> T): T {
    return function.invoke(context)
  }

  private fun <T> preservingValueStack(function: DukContext.() -> T): T {
    val top = context.getTop()
    try {
      return function.invoke(context)
    } finally {
      val addedToStack = (context.getTop() - top).coerceAtLeast(0)
      if (addedToStack > 0) {
        context.popN(addedToStack)
      }
    }
  }

  private fun clearStack() {
    context.popN(context.getTop())
  }

  private fun printStack() {
    println("value stack:")
    val bottom = -context.getTop()
    for(i in -1 downTo bottom) {
      context.dup(i)
      println("  [$i] ${context.getType(-1)} ${context.safeToString(-1)}")
      context.pop()
    }
  }

  private fun assertEmptyStack() {
    require(context.getTop() == 0)
  }

  fun evaluate(source: String) {
    preservingValueStack {
      if (context.pevalString(source).isNonZero) {
        throw IllegalStateException(context.safeToString(-1))
      }
    }
  }

  fun invokeGlobalFunction(functionName: String, vararg args: Any): Any {
    try {
      if (context.getGlobalString(functionName) == 0) {
        throw IllegalStateException("No function found $functionName")
      }

      for (arg in args) {
        require(arg is String)
        context.pushString(arg)
      }

      if (context.pcall(args.size).isNonZero) {
        val error = context.safeToString(-1)
        throw IllegalStateException("Failed to invoke $functionName with error \"$error\"")
      }
      if (context.isString(-1).isTrue) {
        return context.getString(-1)
      }
    } finally {
      clearStack()
    }
    return Unit
  }

  override fun close() {
    cleanup()
  }

  private fun cleanup(): Boolean {
    synchronized(this) {
      if (closed) return false
      context.destroyHeap()
      closed = true
      return true
    }
  }

  protected fun finalize() {
    if (cleanup()) {
      err.println("Leaked instance of ${this::javaClass}${System.identityHashCode(this)}")
    }
  }
  private val Int.isNonZero: Boolean get() = this != 0
  private val Int.isTrue: Boolean get() = this == 1
}


