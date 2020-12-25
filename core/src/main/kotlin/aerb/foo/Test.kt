package aerb.foo

import java.nio.file.Path

object Test {
  init {
    System.load(
      Path.of("../jni/cmake-build-debug/libduktape-jni.dylib").toAbsolutePath().toString()
    )
  }

  private external fun createHeapDefault(): Long

  fun newContext(): DukContext {
    return DukContext(createHeapDefault())
  }
}

@ExperimentalUnsignedTypes
fun main() {
  val method = 1 shl 4
  val strict = 1 shl 5

  val context = Test.newContext()

  context.pushString("""
print('global');
function hello() { print('Hello world!'); }
hello();
print(this);
print(Object.keys(this));
  """)
  context.pushString("filename")
  context.pcompile()
  context.pcall(0)

}