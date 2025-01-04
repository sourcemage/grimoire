case "$HOST" in
  (*-musl)
    OPTS="$OPTS -DLIBCXX_HAS_MUSL_LIBC=YES"
    ;;
esac &&

# Remove -DPIC from compiler flags, produces build errors
CXXFLAGS="${CXXFLAGS//-DPIC}" &&

# Default target, not detected correctly
OPTS="$OPTS -DLLVM_DEFAULT_TARGET_TRIPLE=$HOST" &&

# LLVM_TARGETS
OPTS="$OPTS -DLLVM_TARGETS_TO_BUILD=${LLVM_TARGETS// /;}" &&

# recommended by mesa project
OPTS="$OPTS -DLLVM_LINK_LLVM_DYLIB=1" &&

OPTS="$OPTS -DLLVM_BUILD_BENCHMARKS=OFF" &&
OPTS="$OPTS -DLLVM_INCLUDE_BENCHMARKS=OFF" &&
OPTS="$OPTS -DLLVM_INCLUDE_TESTS=OFF" &&

# prevent unnecessary use of libedit and ncurses
if ! is_depends_enabled $SPELL libedit;then
  OPTS="$OPTS -DLLVM_ENABLE_LIBEDIT=OFF" &&
  OPTS="$OPTS -DLLVM_ENABLE_TERMINFO=OFF" &&
  OPTS="$OPTS -DLLVM_ENABLE_BACKTRACES=OFF"
fi &&

# Enable RTTI if requested, recommended, changing it breaks the ABI
if [[ y == "$LLVM_WITH_RTTI" ]]; then
  OPTS="$OPTS -DLLVM_ENABLE_RTTI=ON"
else
  OPTS="$OPTS -DLLVM_ENABLE_RTTI=OFF"
fi &&

OPTS="$OPTS -DLLVM_TOOL_LIBCLC_BUILD=ON"

if [[ "$LLVM_WITH_BOLT" == y ]] ;then
  OPTS="$OPTS -DLLVM_TOOL_BOLT_BUILD=ON"
fi &&

if [[ "$LLVM_WITH_CLANG" == y ]] ;then
  OPTS="$OPTS -DLLVM_TOOL_CLANG_TOOLS_EXTRA_BUILD=ON" &&
  OPTS="$OPTS -DCLANG_INCLUDE_BENCHMARKS=OFF" &&
  OPTS="$OPTS -DCLANG_INCLUDE_TESTS=OFF"
fi &&

if [[ "$LLVM_WITH_LLD" == y ]] ;then
  OPTS="$OPTS -DLLVM_TOOL_LLD_BUILD=ON"
fi &&

if [[ "$LLVM_WITH_LLDB" == y ]] ;then
  OPTS="$OPTS -DLLVM_TOOL_LLDB_BUILD=ON" &&
  OPTS="$OPTS -DLLDB_INCLUDE_TESTS=OFF"
fi &&

if [[ "$LLVM_WITH_MLIR" == y ]] ;then
  OPTS="$OPTS -DLLVM_TOOL_MLIR_BUILD=ON" &&
  OPTS="$OPTS -DMLIR_ENABLE_PYTHON_BENCHMARKS=OFF"
fi &&

if [[ "$LLVM_WITH_POLLY" == y ]] ;then
  OPTS="$OPTS -DLLVM_TOOL_POLLY_BUILD=ON"
fi &&

# enable requested runtimes
OPTS="$OPTS -DLLVM_ENABLE_RUNTIMES=${LLVM_RUNTIMES// /;}" &&

if list_find "$LLVM_RUNTIMES" "compiler-rt" ;then
  OPTS="$OPTS -DLLVM_TOOL_COMPILER_RT_BUILD=ON" &&
  OPTS="$OPTS -DCOMPILER_RT_INCLUDE_TESTS=OFF"
fi &&

if list_find "$LLVM_RUNTIMES" "libcxx" ;then
  OPTS="$OPTS -DLLVM_TOOL_LIBCXX_BUILD=ON" &&
  # libcxx includes benchmarks by default, which in turn depend ON
  # google-benchmark, so disable them
  OPTS="$OPTS -DLIBCXX_INCLUDE_BENCHMARKS=OFF"
fi &&

if list_find "$LLVM_RUNTIMES" "libcxxabi" ;then
  OPTS="$OPTS -DLLVM_TOOL_LIBCXXABI_BUILD=ON"
fi &&

if list_find "$LLVM_RUNTIMES" "libunwind" ;then
  OPTS="$OPTS -DLLVM_TOOL_LIBUNWIND_BUILD=ON"
fi &&

if list_find "$LLVM_RUNTIMES" "openmp" ;then
  OPTS="$OPTS -DLLVM_TOOL_OPENMP_BUILD=ON"
fi &&

cmake_build -S ../llvm
