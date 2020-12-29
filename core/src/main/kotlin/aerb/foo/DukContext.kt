package aerb.foo

@Suppress("unused")
data class DukContext(
  private val pointer: Long,
  private val handler: DuktapeCallbackHandler
) {

  init {
    setupContext(pointer)
  }

  private external fun setupContext(contextPtr: Long)

  private external fun pushJvmDelegateFunction(contextPtr: Long): Int

  fun pushJvmDelegateFunction(): Int {
    return pushJvmDelegateFunction(pointer)
  }

  fun invokedFromDuktape(): Int {
    return handler.handleDuktapeCall()
  }

  private external fun base64Decode(
    contextPtr: Long,
    idx: Int
  )

  private external fun base64Encode(
    contextPtr: Long,
    idx: Int
  ): String

  private external fun bufferToString(
    contextPtr: Long,
    idx: Int
  ): String

  private external fun call(
    contextPtr: Long,
    nargs: Int
  )

  private external fun callMethod(
    contextPtr: Long,
    nargs: Int
  )

  private external fun callProp(
    contextPtr: Long,
    objIdx: Int,
    nargs: Int
  )

  private external fun cborDecode(
    contextPtr: Long,
    idx: Int,
    decodeFlags: Int
  )

  private external fun cborEncode(
    contextPtr: Long,
    idx: Int,
    encodeFlags: Int
  )

  private external fun checkStack(
    contextPtr: Long,
    extra: Int
  ): Int

  private external fun checkStackTop(
    contextPtr: Long,
    top: Int
  ): Int

  private external fun checkType(
    contextPtr: Long,
    idx: Int,
    type: Int
  ): Int

  private external fun checkTypeMask(
    contextPtr: Long,
    idx: Int,
    mask: Int
  ): Int

  private external fun compact(
    contextPtr: Long,
    objIdx: Int
  )

  private external fun compile(
    contextPtr: Long,
    flags: Int
  )

  private external fun compileString(
    contextPtr: Long,
    flags: Int,
    src: String
  )

  private external fun compileStringFilename(
    contextPtr: Long,
    flags: Int,
    src: String
  )

  private external fun concat(
    contextPtr: Long,
    count: Int
  )

  private external fun copy(
    contextPtr: Long,
    fromIdx: Int,
    toIdx: Int
  )

  private external fun debuggerCooperate(
    contextPtr: Long
  )

  private external fun debuggerDetach(
    contextPtr: Long
  )

  private external fun debuggerNotify(
    contextPtr: Long,
    nvalues: Int
  ): Int

  private external fun debuggerPause(
    contextPtr: Long
  )

  private external fun defProp(
    contextPtr: Long,
    objIdx: Int,
    flags: Int
  )

  private external fun delProp(
    contextPtr: Long,
    objIdx: Int
  ): Int

  private external fun delPropIndex(
    contextPtr: Long,
    objIdx: Int,
    arrIdx: Int
  ): Int

  private external fun delPropLiteral(
    contextPtr: Long,
    objIdx: Int,
    keyLiteral: String
  ): Int

  private external fun delPropString(
    contextPtr: Long,
    objIdx: Int,
    key: String
  ): Int

  private external fun destroyHeap(
    contextPtr: Long
  )

  private external fun dumpFunction(
    contextPtr: Long
  )

  private external fun dup(
    contextPtr: Long,
    fromIdx: Int
  )

  private external fun dupTop(
    contextPtr: Long
  )

  private external fun enum(
    contextPtr: Long,
    objIdx: Int,
    enumFlags: Int
  )

  private external fun equals(
    contextPtr: Long,
    idx1: Int,
    idx2: Int
  ): Int

  private external fun eval(
    contextPtr: Long
  )

  private external fun evalNoresult(
    contextPtr: Long
  )

  private external fun evalString(
    contextPtr: Long,
    src: String
  )

  private external fun evalStringNoresult(
    contextPtr: Long,
    src: String
  )

  private external fun fatal(
    contextPtr: Long,
    errMsg: String
  ): Int

  private external fun freeze(
    contextPtr: Long,
    objIdx: Int
  )

  private external fun gc(
    contextPtr: Long,
    flags: Int
  )

  private external fun getBoolean(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun getBooleanDefault(
    contextPtr: Long,
    idx: Int,
    defValue: Int
  ): Int

  private external fun getCurrentMagic(
    contextPtr: Long
  ): Int

  private external fun getErrorCode(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun getFinalizer(
    contextPtr: Long,
    idx: Int
  )

  private external fun getGlobalLiteral(
    contextPtr: Long,
    keyLiteral: String
  ): Int

  private external fun getGlobalString(
    contextPtr: Long,
    key: String
  ): Int

  private external fun getInt(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun getIntDefault(
    contextPtr: Long,
    idx: Int,
    defValue: Int
  ): Int

  private external fun getMagic(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun getProp(
    contextPtr: Long,
    objIdx: Int
  ): Int

  private external fun getPropDesc(
    contextPtr: Long,
    objIdx: Int,
    flags: Int
  )

  private external fun getPropIndex(
    contextPtr: Long,
    objIdx: Int,
    arrIdx: Int
  ): Int

  private external fun getPropString(
    contextPtr: Long,
    objIdx: Int,
    key: String
  ): Int

  private external fun getPrototype(
    contextPtr: Long,
    idx: Int
  )

  private external fun getString(
    contextPtr: Long,
    idx: Int
  ): String

  private external fun getStringDefault(
    contextPtr: Long,
    idx: Int,
    defValue: String
  ): String

  private external fun getTop(
    contextPtr: Long
  ): Int

  private external fun getTopIndex(
    contextPtr: Long
  ): Int

  private external fun getType(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun getTypeMask(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun getUint(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun getUintDefault(
    contextPtr: Long,
    idx: Int,
    defValue: Int
  ): Int

  private external fun hasProp(
    contextPtr: Long,
    objIdx: Int
  ): Int

  private external fun hasPropIndex(
    contextPtr: Long,
    objIdx: Int,
    arrIdx: Int
  ): Int

  private external fun hasPropLiteral(
    contextPtr: Long,
    objIdx: Int,
    keyLiteral: String
  ): Int

  private external fun hasPropString(
    contextPtr: Long,
    objIdx: Int,
    key: String
  ): Int

  private external fun hexDecode(
    contextPtr: Long,
    idx: Int
  )

  private external fun hexEncode(
    contextPtr: Long,
    idx: Int
  ): String

  private external fun insert(
    contextPtr: Long,
    toIdx: Int
  )

  private external fun inspectCallstackEntry(
    contextPtr: Long,
    level: Int
  )

  private external fun inspectValue(
    contextPtr: Long,
    idx: Int
  )

  private external fun instanceof(
    contextPtr: Long,
    idx1: Int,
    idx2: Int
  ): Int

  private external fun isArray(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isBoolean(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isBoundFunction(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isBuffer(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isBufferData(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isCFunction(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isCallable(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isConstructable(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isConstructorCall(
    contextPtr: Long
  ): Int

  private external fun isDynamicBuffer(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isEcmascriptFunction(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isError(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isEvalError(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isFixedBuffer(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isFunction(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isLightfunc(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isNan(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isNull(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isNullOrUndefined(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isNumber(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isObject(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isObjectCoercible(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isPointer(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isPrimitive(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isRangeError(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isReferenceError(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isStrictCall(
    contextPtr: Long
  ): Int

  private external fun isString(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isSymbol(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isSyntaxError(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isThread(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isTypeError(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isUndefined(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isUriError(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun isValidIndex(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun join(
    contextPtr: Long,
    count: Int
  )

  private external fun jsonDecode(
    contextPtr: Long,
    idx: Int
  )

  private external fun jsonEncode(
    contextPtr: Long,
    idx: Int
  ): String

  private external fun loadFunction(
    contextPtr: Long
  )

  private external fun new(
    contextPtr: Long,
    nargs: Int
  )

  private external fun next(
    contextPtr: Long,
    enumIdx: Int,
    getValue: Int
  ): Int

  private external fun normalizeIndex(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun optBoolean(
    contextPtr: Long,
    idx: Int,
    defValue: Int
  ): Int

  private external fun optInt(
    contextPtr: Long,
    idx: Int,
    defValue: Int
  ): Int

  private external fun optString(
    contextPtr: Long,
    idx: Int,
    defPtr: String
  ): String

  private external fun optUint(
    contextPtr: Long,
    idx: Int,
    defValue: Int
  ): Int

  private external fun pcall(
    contextPtr: Long,
    nargs: Int
  ): Int

  private external fun pcallMethod(
    contextPtr: Long,
    nargs: Int
  ): Int

  private external fun pcallProp(
    contextPtr: Long,
    objIdx: Int,
    nargs: Int
  ): Int

  private external fun pcompile(
    contextPtr: Long,
    flags: Int
  ): Int

  private external fun pcompileString(
    contextPtr: Long,
    flags: Int,
    src: String
  ): Int

  private external fun pcompileStringFilename(
    contextPtr: Long,
    flags: Int,
    src: String
  ): Int

  private external fun peval(
    contextPtr: Long
  ): Int

  private external fun pevalNoresult(
    contextPtr: Long
  ): Int

  private external fun pevalString(
    contextPtr: Long,
    src: String
  ): Int

  private external fun pevalStringNoresult(
    contextPtr: Long,
    src: String
  ): Int

  private external fun pnew(
    contextPtr: Long,
    nargs: Int
  ): Int

  private external fun pop(
    contextPtr: Long
  )

  private external fun pop2(
    contextPtr: Long
  )

  private external fun pop3(
    contextPtr: Long
  )

  private external fun popN(
    contextPtr: Long,
    count: Int
  )

  private external fun pull(
    contextPtr: Long,
    fromIdx: Int
  )

  private external fun pushArray(
    contextPtr: Long
  ): Int

  private external fun pushBareArray(
    contextPtr: Long
  ): Int

  private external fun pushBareObject(
    contextPtr: Long
  ): Int

  private external fun pushBoolean(
    contextPtr: Long,
    value: Int
  )

  private external fun pushContextDump(
    contextPtr: Long
  )

  private external fun pushCurrentFunction(
    contextPtr: Long
  )

  private external fun pushCurrentThread(
    contextPtr: Long
  )

  private external fun pushExternalBuffer(
    contextPtr: Long
  )

  private external fun pushFalse(
    contextPtr: Long
  )

  private external fun pushGlobalObject(
    contextPtr: Long
  )

  private external fun pushGlobalStash(
    contextPtr: Long
  )

  private external fun pushHeapStash(
    contextPtr: Long
  )

  private external fun pushInt(
    contextPtr: Long,
    value: Int
  )

  private external fun pushLiteral(
    contextPtr: Long,
    strLiteral: String
  ): String

  private external fun pushNan(
    contextPtr: Long
  )

  private external fun pushNewTarget(
    contextPtr: Long
  )

  private external fun pushNull(
    contextPtr: Long
  )

  private external fun pushObject(
    contextPtr: Long
  ): Int

  private external fun pushProxy(
    contextPtr: Long,
    proxyFlags: Int
  ): Int

  private external fun pushString(
    contextPtr: Long,
    str: String
  ): String

  private external fun pushThis(
    contextPtr: Long
  )

  private external fun pushThread(
    contextPtr: Long
  ): Int

  private external fun pushThreadNewGlobalenv(
    contextPtr: Long
  ): Int

  private external fun pushThreadStash(
    contextPtr: Long,
    targetCtx: Long
  )

  private external fun pushTrue(
    contextPtr: Long
  )

  private external fun pushUint(
    contextPtr: Long,
    value: Int
  )

  private external fun pushUndefined(
    contextPtr: Long
  )

  private external fun putGlobalLiteral(
    contextPtr: Long,
    keyLiteral: String
  ): Int

  private external fun putGlobalString(
    contextPtr: Long,
    key: String
  ): Int

  private external fun putProp(
    contextPtr: Long,
    objIdx: Int
  ): Int

  private external fun putPropIndex(
    contextPtr: Long,
    objIdx: Int,
    arrIdx: Int
  ): Int

  private external fun putPropLiteral(
    contextPtr: Long,
    objIdx: Int,
    keyLiteral: String
  ): Int

  private external fun putPropString(
    contextPtr: Long,
    objIdx: Int,
    key: String
  ): Int

  private external fun remove(
    contextPtr: Long,
    idx: Int
  )

  private external fun replace(
    contextPtr: Long,
    toIdx: Int
  )

  private external fun requireBoolean(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun requireCallable(
    contextPtr: Long,
    idx: Int
  )

  private external fun requireConstructable(
    contextPtr: Long,
    idx: Int
  )

  private external fun requireConstructorCall(
    contextPtr: Long
  )

  private external fun requireFunction(
    contextPtr: Long,
    idx: Int
  )

  private external fun requireInt(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun requireNormalizeIndex(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun requireNull(
    contextPtr: Long,
    idx: Int
  )

  private external fun requireObject(
    contextPtr: Long,
    idx: Int
  )

  private external fun requireObjectCoercible(
    contextPtr: Long,
    idx: Int
  )

  private external fun requireStack(
    contextPtr: Long,
    extra: Int
  )

  private external fun requireStackTop(
    contextPtr: Long,
    top: Int
  )

  private external fun requireString(
    contextPtr: Long,
    idx: Int
  ): String

  private external fun requireTopIndex(
    contextPtr: Long
  ): Int

  private external fun requireTypeMask(
    contextPtr: Long,
    idx: Int,
    mask: Int
  )

  private external fun requireUint(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun requireUndefined(
    contextPtr: Long,
    idx: Int
  )

  private external fun requireValidIndex(
    contextPtr: Long,
    idx: Int
  )

  private external fun safeToStacktrace(
    contextPtr: Long,
    idx: Int
  ): String

  private external fun safeToString(
    contextPtr: Long,
    idx: Int
  ): String

  private external fun samevalue(
    contextPtr: Long,
    idx1: Int,
    idx2: Int
  ): Int

  private external fun seal(
    contextPtr: Long,
    objIdx: Int
  )

  private external fun setFinalizer(
    contextPtr: Long,
    idx: Int
  )

  private external fun setGlobalObject(
    contextPtr: Long
  )

  private external fun setMagic(
    contextPtr: Long,
    idx: Int,
    magic: Int
  )

  private external fun setPrototype(
    contextPtr: Long,
    idx: Int
  )

  private external fun setTop(
    contextPtr: Long,
    idx: Int
  )

  private external fun strictEquals(
    contextPtr: Long,
    idx1: Int,
    idx2: Int
  ): Int

  private external fun swap(
    contextPtr: Long,
    idx1: Int,
    idx2: Int
  )

  private external fun swapTop(
    contextPtr: Long,
    idx: Int
  )

  private external fun `throw`(
    contextPtr: Long
  ): Int

  private external fun toBoolean(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun toInt(
    contextPtr: Long,
    index: Int
  ): Int

  private external fun toNull(
    contextPtr: Long,
    idx: Int
  )

  private external fun toObject(
    contextPtr: Long,
    idx: Int
  )

  private external fun toPrimitive(
    contextPtr: Long,
    idx: Int,
    hint: Int
  )

  private external fun toStacktrace(
    contextPtr: Long,
    idx: Int
  ): String

  private external fun toString(
    contextPtr: Long,
    idx: Int
  ): String

  private external fun toUint(
    contextPtr: Long,
    idx: Int
  ): Int

  private external fun toUndefined(
    contextPtr: Long,
    idx: Int
  )

  private external fun trim(
    contextPtr: Long,
    idx: Int
  )

  private external fun xcopyTop(
    toCtx: Long,
    fromCtx: Long,
    count: Int
  )

  private external fun xmoveTop(
    toCtx: Long,
    fromCtx: Long,
    count: Int
  )

  fun base64Decode(
    idx: Int,
  ) {
    base64Decode(pointer, idx)
  }

  fun base64Encode(
    idx: Int,
  ): String {
    return base64Encode(pointer, idx)
  }

  fun bufferToString(
    idx: Int,
  ): String {
    return bufferToString(pointer, idx)
  }

  fun call(
    nargs: Int,
  ) {
    call(pointer, nargs)
  }

  fun callMethod(
    nargs: Int,
  ) {
    callMethod(pointer, nargs)
  }

  fun callProp(
    objIdx: Int,
    nargs: Int,
  ) {
    callProp(pointer, objIdx, nargs)
  }

  fun cborDecode(
    idx: Int,
    decodeFlags: Int,
  ) {
    cborDecode(pointer, idx, decodeFlags)
  }

  fun cborEncode(
    idx: Int,
    encodeFlags: Int,
  ) {
    cborEncode(pointer, idx, encodeFlags)
  }

  fun checkStack(
    extra: Int,
  ): Int {
    return checkStack(pointer, extra)
  }

  fun checkStackTop(
    top: Int,
  ): Int {
    return checkStackTop(pointer, top)
  }

  fun checkType(
    idx: Int,
    type: Int,
  ): Int {
    return checkType(pointer, idx, type)
  }

  fun checkTypeMask(
    idx: Int,
    mask: Int,
  ): Int {
    return checkTypeMask(pointer, idx, mask)
  }

  fun compact(
    objIdx: Int,
  ) {
    compact(pointer, objIdx)
  }

  fun compile(
    flags: Int,
  ) {
    compile(pointer, flags)
  }

  fun compileString(
    flags: Int,
    src: String,
  ) {
    compileString(pointer, flags, src)
  }

  fun compileStringFilename(
    flags: Int,
    src: String,
  ) {
    compileStringFilename(pointer, flags, src)
  }

  fun concat(
    count: Int,
  ) {
    concat(pointer, count)
  }

  fun copy(
    fromIdx: Int,
    toIdx: Int,
  ) {
    copy(pointer, fromIdx, toIdx)
  }

  fun debuggerCooperate(
  ) {
    debuggerCooperate(pointer)
  }

  fun debuggerDetach(
  ) {
    debuggerDetach(pointer)
  }

  fun debuggerNotify(
    nvalues: Int,
  ): Int {
    return debuggerNotify(pointer, nvalues)
  }

  fun debuggerPause(
  ) {
    debuggerPause(pointer)
  }

  fun defProp(
    objIdx: Int,
    flags: Int,
  ) {
    defProp(pointer, objIdx, flags)
  }

  fun delProp(
    objIdx: Int,
  ): Int {
    return delProp(pointer, objIdx)
  }

  fun delPropIndex(
    objIdx: Int,
    arrIdx: Int,
  ): Int {
    return delPropIndex(pointer, objIdx, arrIdx)
  }

  fun delPropLiteral(
    objIdx: Int,
    keyLiteral: String,
  ): Int {
    return delPropLiteral(pointer, objIdx, keyLiteral)
  }

  fun delPropString(
    objIdx: Int,
    key: String,
  ): Int {
    return delPropString(pointer, objIdx, key)
  }

  fun destroyHeap(
  ) {
    destroyHeap(pointer)
  }

  fun dumpFunction(
  ) {
    dumpFunction(pointer)
  }

  fun dup(
    fromIdx: Int,
  ) {
    dup(pointer, fromIdx)
  }

  fun dupTop(
  ) {
    dupTop(pointer)
  }

  fun enum(
    objIdx: Int,
    enumFlags: Int,
  ) {
    enum(pointer, objIdx, enumFlags)
  }

  fun equals(
    idx1: Int,
    idx2: Int,
  ): Int {
    return equals(pointer, idx1, idx2)
  }

  fun eval(
  ) {
    eval(pointer)
  }

  fun evalNoresult(
  ) {
    evalNoresult(pointer)
  }

  fun evalString(
    src: String,
  ) {
    evalString(pointer, src)
  }

  fun evalStringNoresult(
    src: String,
  ) {
    evalStringNoresult(pointer, src)
  }

  fun fatal(
    errMsg: String,
  ): Int {
    return fatal(pointer, errMsg)
  }

  fun freeze(
    objIdx: Int,
  ) {
    freeze(pointer, objIdx)
  }

  fun gc(
    flags: Int,
  ) {
    gc(pointer, flags)
  }

  fun getBoolean(
    idx: Int,
  ): Int {
    return getBoolean(pointer, idx)
  }

  fun getBooleanDefault(
    idx: Int,
    defValue: Int,
  ): Int {
    return getBooleanDefault(pointer, idx, defValue)
  }

  fun getCurrentMagic(
  ): Int {
    return getCurrentMagic(pointer)
  }

  fun getErrorCode(
    idx: Int,
  ): Int {
    return getErrorCode(pointer, idx)
  }

  fun getFinalizer(
    idx: Int,
  ) {
    getFinalizer(pointer, idx)
  }

  fun getGlobalLiteral(
    keyLiteral: String,
  ): Int {
    return getGlobalLiteral(pointer, keyLiteral)
  }

  fun getGlobalString(
    key: String,
  ): Int {
    return getGlobalString(pointer, key)
  }

  fun getInt(
    idx: Int,
  ): Int {
    return getInt(pointer, idx)
  }

  fun getIntDefault(
    idx: Int,
    defValue: Int,
  ): Int {
    return getIntDefault(pointer, idx, defValue)
  }

  fun getMagic(
    idx: Int,
  ): Int {
    return getMagic(pointer, idx)
  }

  fun getProp(
    objIdx: Int,
  ): Int {
    return getProp(pointer, objIdx)
  }

  fun getPropDesc(
    objIdx: Int,
    flags: Int,
  ) {
    getPropDesc(pointer, objIdx, flags)
  }

  fun getPropIndex(
    objIdx: Int,
    arrIdx: Int,
  ): Int {
    return getPropIndex(pointer, objIdx, arrIdx)
  }

  fun getPropString(
    objIdx: Int,
    key: String,
  ): Int {
    return getPropString(pointer, objIdx, key)
  }

  fun getPrototype(
    idx: Int,
  ) {
    getPrototype(pointer, idx)
  }

  fun getString(
    idx: Int,
  ): String {
    return getString(pointer, idx)
  }

  fun getStringDefault(
    idx: Int,
    defValue: String,
  ): String {
    return getStringDefault(pointer, idx, defValue)
  }

  fun getTop(
  ): Int {
    return getTop(pointer)
  }

  fun getTopIndex(
  ): Int {
    return getTopIndex(pointer)
  }

  fun getType(
    idx: Int,
  ): Int {
    return getType(pointer, idx)
  }

  fun getTypeMask(
    idx: Int,
  ): Int {
    return getTypeMask(pointer, idx)
  }

  fun getUint(
    idx: Int,
  ): Int {
    return getUint(pointer, idx)
  }

  fun getUintDefault(
    idx: Int,
    defValue: Int,
  ): Int {
    return getUintDefault(pointer, idx, defValue)
  }

  fun hasProp(
    objIdx: Int,
  ): Int {
    return hasProp(pointer, objIdx)
  }

  fun hasPropIndex(
    objIdx: Int,
    arrIdx: Int,
  ): Int {
    return hasPropIndex(pointer, objIdx, arrIdx)
  }

  fun hasPropLiteral(
    objIdx: Int,
    keyLiteral: String,
  ): Int {
    return hasPropLiteral(pointer, objIdx, keyLiteral)
  }

  fun hasPropString(
    objIdx: Int,
    key: String,
  ): Int {
    return hasPropString(pointer, objIdx, key)
  }

  fun hexDecode(
    idx: Int,
  ) {
    hexDecode(pointer, idx)
  }

  fun hexEncode(
    idx: Int,
  ): String {
    return hexEncode(pointer, idx)
  }

  fun insert(
    toIdx: Int,
  ) {
    insert(pointer, toIdx)
  }

  fun inspectCallstackEntry(
    level: Int,
  ) {
    inspectCallstackEntry(pointer, level)
  }

  fun inspectValue(
    idx: Int,
  ) {
    inspectValue(pointer, idx)
  }

  fun instanceof(
    idx1: Int,
    idx2: Int,
  ): Int {
    return instanceof(pointer, idx1, idx2)
  }

  fun isArray(
    idx: Int,
  ): Int {
    return isArray(pointer, idx)
  }

  fun isBoolean(
    idx: Int,
  ): Int {
    return isBoolean(pointer, idx)
  }

  fun isBoundFunction(
    idx: Int,
  ): Int {
    return isBoundFunction(pointer, idx)
  }

  fun isBuffer(
    idx: Int,
  ): Int {
    return isBuffer(pointer, idx)
  }

  fun isBufferData(
    idx: Int,
  ): Int {
    return isBufferData(pointer, idx)
  }

  fun isCFunction(
    idx: Int,
  ): Int {
    return isCFunction(pointer, idx)
  }

  fun isCallable(
    idx: Int,
  ): Int {
    return isCallable(pointer, idx)
  }

  fun isConstructable(
    idx: Int,
  ): Int {
    return isConstructable(pointer, idx)
  }

  fun isConstructorCall(
  ): Int {
    return isConstructorCall(pointer)
  }

  fun isDynamicBuffer(
    idx: Int,
  ): Int {
    return isDynamicBuffer(pointer, idx)
  }

  fun isEcmascriptFunction(
    idx: Int,
  ): Int {
    return isEcmascriptFunction(pointer, idx)
  }

  fun isError(
    idx: Int,
  ): Int {
    return isError(pointer, idx)
  }

  fun isEvalError(
    idx: Int,
  ): Int {
    return isEvalError(pointer, idx)
  }

  fun isFixedBuffer(
    idx: Int,
  ): Int {
    return isFixedBuffer(pointer, idx)
  }

  fun isFunction(
    idx: Int,
  ): Int {
    return isFunction(pointer, idx)
  }

  fun isLightfunc(
    idx: Int,
  ): Int {
    return isLightfunc(pointer, idx)
  }

  fun isNan(
    idx: Int,
  ): Int {
    return isNan(pointer, idx)
  }

  fun isNull(
    idx: Int,
  ): Int {
    return isNull(pointer, idx)
  }

  fun isNullOrUndefined(
    idx: Int,
  ): Int {
    return isNullOrUndefined(pointer, idx)
  }

  fun isNumber(
    idx: Int,
  ): Int {
    return isNumber(pointer, idx)
  }

  fun isObject(
    idx: Int,
  ): Int {
    return isObject(pointer, idx)
  }

  fun isObjectCoercible(
    idx: Int,
  ): Int {
    return isObjectCoercible(pointer, idx)
  }

  fun isPointer(
    idx: Int,
  ): Int {
    return isPointer(pointer, idx)
  }

  fun isPrimitive(
    idx: Int,
  ): Int {
    return isPrimitive(pointer, idx)
  }

  fun isRangeError(
    idx: Int,
  ): Int {
    return isRangeError(pointer, idx)
  }

  fun isReferenceError(
    idx: Int,
  ): Int {
    return isReferenceError(pointer, idx)
  }

  fun isStrictCall(
  ): Int {
    return isStrictCall(pointer)
  }

  fun isString(
    idx: Int,
  ): Int {
    return isString(pointer, idx)
  }

  fun isSymbol(
    idx: Int,
  ): Int {
    return isSymbol(pointer, idx)
  }

  fun isSyntaxError(
    idx: Int,
  ): Int {
    return isSyntaxError(pointer, idx)
  }

  fun isThread(
    idx: Int,
  ): Int {
    return isThread(pointer, idx)
  }

  fun isTypeError(
    idx: Int,
  ): Int {
    return isTypeError(pointer, idx)
  }

  fun isUndefined(
    idx: Int,
  ): Int {
    return isUndefined(pointer, idx)
  }

  fun isUriError(
    idx: Int,
  ): Int {
    return isUriError(pointer, idx)
  }

  fun isValidIndex(
    idx: Int,
  ): Int {
    return isValidIndex(pointer, idx)
  }

  fun join(
    count: Int,
  ) {
    join(pointer, count)
  }

  fun jsonDecode(
    idx: Int,
  ) {
    jsonDecode(pointer, idx)
  }

  fun jsonEncode(
    idx: Int,
  ): String {
    return jsonEncode(pointer, idx)
  }

  fun loadFunction(
  ) {
    loadFunction(pointer)
  }

  fun new(
    nargs: Int,
  ) {
    new(pointer, nargs)
  }

  fun next(
    enumIdx: Int,
    getValue: Int,
  ): Int {
    return next(pointer, enumIdx, getValue)
  }

  fun normalizeIndex(
    idx: Int,
  ): Int {
    return normalizeIndex(pointer, idx)
  }

  fun optBoolean(
    idx: Int,
    defValue: Int,
  ): Int {
    return optBoolean(pointer, idx, defValue)
  }

  fun optInt(
    idx: Int,
    defValue: Int,
  ): Int {
    return optInt(pointer, idx, defValue)
  }

  fun optString(
    idx: Int,
    defPtr: String,
  ): String {
    return optString(pointer, idx, defPtr)
  }

  fun optUint(
    idx: Int,
    defValue: Int,
  ): Int {
    return optUint(pointer, idx, defValue)
  }

  fun pcall(
    nargs: Int,
  ): Int {
    return pcall(pointer, nargs)
  }

  fun pcallMethod(
    nargs: Int,
  ): Int {
    return pcallMethod(pointer, nargs)
  }

  fun pcallProp(
    objIdx: Int,
    nargs: Int,
  ): Int {
    return pcallProp(pointer, objIdx, nargs)
  }

  fun pcompile(
    flags: Int,
  ): Int {
    return pcompile(pointer, flags)
  }

  fun pcompileString(
    flags: Int,
    src: String,
  ): Int {
    return pcompileString(pointer, flags, src)
  }

  fun pcompileStringFilename(
    flags: Int,
    src: String,
  ): Int {
    return pcompileStringFilename(pointer, flags, src)
  }

  fun peval(
  ): Int {
    return peval(pointer)
  }

  fun pevalNoresult(
  ): Int {
    return pevalNoresult(pointer)
  }

  fun pevalString(
    src: String,
  ): Int {
    return pevalString(pointer, src)
  }

  fun pevalStringNoresult(
    src: String,
  ): Int {
    return pevalStringNoresult(pointer, src)
  }

  fun pnew(
    nargs: Int,
  ): Int {
    return pnew(pointer, nargs)
  }

  fun pop(
  ) {
    pop(pointer)
  }

  fun pop2(
  ) {
    pop2(pointer)
  }

  fun pop3(
  ) {
    pop3(pointer)
  }

  fun popN(
    count: Int,
  ) {
    popN(pointer, count)
  }

  fun pull(
    fromIdx: Int,
  ) {
    pull(pointer, fromIdx)
  }

  fun pushArray(
  ): Int {
    return pushArray(pointer)
  }

  fun pushBareArray(
  ): Int {
    return pushBareArray(pointer)
  }

  fun pushBareObject(
  ): Int {
    return pushBareObject(pointer)
  }

  fun pushBoolean(
    value: Int,
  ) {
    pushBoolean(pointer, value)
  }

  fun pushContextDump(
  ) {
    pushContextDump(pointer)
  }

  fun pushCurrentFunction(
  ) {
    pushCurrentFunction(pointer)
  }

  fun pushCurrentThread(
  ) {
    pushCurrentThread(pointer)
  }

  fun pushExternalBuffer(
  ) {
    pushExternalBuffer(pointer)
  }

  fun pushFalse(
  ) {
    pushFalse(pointer)
  }

  fun pushGlobalObject(
  ) {
    pushGlobalObject(pointer)
  }

  fun pushGlobalStash(
  ) {
    pushGlobalStash(pointer)
  }

  fun pushHeapStash(
  ) {
    pushHeapStash(pointer)
  }

  fun pushInt(
    value: Int,
  ) {
    pushInt(pointer, value)
  }

  fun pushLiteral(
    strLiteral: String,
  ): String {
    return pushLiteral(pointer, strLiteral)
  }

  fun pushNan(
  ) {
    pushNan(pointer)
  }

  fun pushNewTarget(
  ) {
    pushNewTarget(pointer)
  }

  fun pushNull(
  ) {
    pushNull(pointer)
  }

  fun pushObject(
  ): Int {
    return pushObject(pointer)
  }

  fun pushProxy(
    proxyFlags: Int,
  ): Int {
    return pushProxy(pointer, proxyFlags)
  }

  fun pushString(
    str: String,
  ): String {
    return pushString(pointer, str)
  }

  fun pushThis(
  ) {
    pushThis(pointer)
  }

  fun pushThread(
  ): Int {
    return pushThread(pointer)
  }

  fun pushThreadNewGlobalenv(
  ): Int {
    return pushThreadNewGlobalenv(pointer)
  }

  fun pushThreadStash(
    targetCtx: Long,
  ) {
    pushThreadStash(pointer, targetCtx)
  }

  fun pushTrue(
  ) {
    pushTrue(pointer)
  }

  fun pushUint(
    value: Int,
  ) {
    pushUint(pointer, value)
  }

  fun pushUndefined(
  ) {
    pushUndefined(pointer)
  }

  fun putGlobalLiteral(
    keyLiteral: String,
  ): Int {
    return putGlobalLiteral(pointer, keyLiteral)
  }

  fun putGlobalString(
    key: String,
  ): Int {
    return putGlobalString(pointer, key)
  }

  fun putProp(
    objIdx: Int,
  ): Int {
    return putProp(pointer, objIdx)
  }

  fun putPropIndex(
    objIdx: Int,
    arrIdx: Int,
  ): Int {
    return putPropIndex(pointer, objIdx, arrIdx)
  }

  fun putPropLiteral(
    objIdx: Int,
    keyLiteral: String,
  ): Int {
    return putPropLiteral(pointer, objIdx, keyLiteral)
  }

  fun putPropString(
    objIdx: Int,
    key: String,
  ): Int {
    return putPropString(pointer, objIdx, key)
  }

  fun remove(
    idx: Int,
  ) {
    remove(pointer, idx)
  }

  fun replace(
    toIdx: Int,
  ) {
    replace(pointer, toIdx)
  }

  fun requireBoolean(
    idx: Int,
  ): Int {
    return requireBoolean(pointer, idx)
  }

  fun requireCallable(
    idx: Int,
  ) {
    requireCallable(pointer, idx)
  }

  fun requireConstructable(
    idx: Int,
  ) {
    requireConstructable(pointer, idx)
  }

  fun requireConstructorCall(
  ) {
    requireConstructorCall(pointer)
  }

  fun requireFunction(
    idx: Int,
  ) {
    requireFunction(pointer, idx)
  }

  fun requireInt(
    idx: Int,
  ): Int {
    return requireInt(pointer, idx)
  }

  fun requireNormalizeIndex(
    idx: Int,
  ): Int {
    return requireNormalizeIndex(pointer, idx)
  }

  fun requireNull(
    idx: Int,
  ) {
    requireNull(pointer, idx)
  }

  fun requireObject(
    idx: Int,
  ) {
    requireObject(pointer, idx)
  }

  fun requireObjectCoercible(
    idx: Int,
  ) {
    requireObjectCoercible(pointer, idx)
  }

  fun requireStack(
    extra: Int,
  ) {
    requireStack(pointer, extra)
  }

  fun requireStackTop(
    top: Int,
  ) {
    requireStackTop(pointer, top)
  }

  fun requireString(
    idx: Int,
  ): String {
    return requireString(pointer, idx)
  }

  fun requireTopIndex(
  ): Int {
    return requireTopIndex(pointer)
  }

  fun requireTypeMask(
    idx: Int,
    mask: Int,
  ) {
    requireTypeMask(pointer, idx, mask)
  }

  fun requireUint(
    idx: Int,
  ): Int {
    return requireUint(pointer, idx)
  }

  fun requireUndefined(
    idx: Int,
  ) {
    requireUndefined(pointer, idx)
  }

  fun requireValidIndex(
    idx: Int,
  ) {
    requireValidIndex(pointer, idx)
  }

  fun safeToStacktrace(
    idx: Int,
  ): String {
    return safeToStacktrace(pointer, idx)
  }

  fun safeToString(
    idx: Int,
  ): String {
    return safeToString(pointer, idx)
  }

  fun samevalue(
    idx1: Int,
    idx2: Int,
  ): Int {
    return samevalue(pointer, idx1, idx2)
  }

  fun seal(
    objIdx: Int,
  ) {
    seal(pointer, objIdx)
  }

  fun setFinalizer(
    idx: Int,
  ) {
    setFinalizer(pointer, idx)
  }

  fun setGlobalObject(
  ) {
    setGlobalObject(pointer)
  }

  fun setMagic(
    idx: Int,
    magic: Int,
  ) {
    setMagic(pointer, idx, magic)
  }

  fun setPrototype(
    idx: Int,
  ) {
    setPrototype(pointer, idx)
  }

  fun setTop(
    idx: Int,
  ) {
    setTop(pointer, idx)
  }

  fun strictEquals(
    idx1: Int,
    idx2: Int,
  ): Int {
    return strictEquals(pointer, idx1, idx2)
  }

  fun swap(
    idx1: Int,
    idx2: Int,
  ) {
    swap(pointer, idx1, idx2)
  }

  fun swapTop(
    idx: Int,
  ) {
    swapTop(pointer, idx)
  }

  fun `throw`(
  ): Int {
    return `throw`(pointer)
  }

  fun toBoolean(
    idx: Int,
  ): Int {
    return toBoolean(pointer, idx)
  }

  fun toInt(
    index: Int,
  ): Int {
    return toInt(pointer, index)
  }

  fun toNull(
    idx: Int,
  ) {
    toNull(pointer, idx)
  }

  fun toObject(
    idx: Int,
  ) {
    toObject(pointer, idx)
  }

  fun toPrimitive(
    idx: Int,
    hint: Int,
  ) {
    toPrimitive(pointer, idx, hint)
  }

  fun toStacktrace(
    idx: Int,
  ): String {
    return toStacktrace(pointer, idx)
  }

  fun toString(
    idx: Int,
  ): String {
    return toString(pointer, idx)
  }

  fun toUint(
    idx: Int,
  ): Int {
    return toUint(pointer, idx)
  }

  fun toUndefined(
    idx: Int,
  ) {
    toUndefined(pointer, idx)
  }

  fun trim(
    idx: Int,
  ) {
    trim(pointer, idx)
  }
}
