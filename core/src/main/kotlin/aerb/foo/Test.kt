package aerb.foo

import java.nio.file.Path

interface DuktapeCallbackHandler {
  fun handleDuktapeCall(): Int
}

object Test {
  init {
    System.load(
      Path.of("../jni/cmake-build-debug/libduktape-jni.dylib").toAbsolutePath().toString()
    )
  }

  private external fun createHeapDefault(): Long

  fun newContext(handler: DuktapeCallbackHandler): DukContext {
    return DukContext(createHeapDefault(), handler)
  }
}

@ExperimentalUnsignedTypes
fun main() {
  val method = 1 shl 4
  val strict = 1 shl 5

  DuktapeEngine().use { engine ->
    // engine.evaluate(
    //   """
    //   function hello() {
    //     print('Hello world!');
    //     return "hello!";
    //   }
    //   """.trimIndent()
    // )
    // repeat(3) {
    //   println(engine.invokeGlobalFunction("hello"))
    // }

  }





//   context.pushString("""
// print('global');
//
// hello();
// print(this);
// print(Object.keys(this));
//   """)
//   println(context.peval())
//   println(context.pop())
//   println(context.getTopIndex().toUInt())
//   context.getGlobalString("hello")
//   println(context.getTopIndex().toUInt())
//   println(context.pcall(0))
//   println(context.getTopIndex().toUInt())
//   println(context.getType(0))
//
//
//   context.destroyHeap()
}