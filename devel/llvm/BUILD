case "$HOST" in
  (*-musl)
    OPTS="$OPTS -DLIBCXX_HAS_MUSL_LIBC=YES"
    ;;
esac &&

# Remove -DPIC from compiler flags, produces build errors
CXXFLAGS="${CXXFLAGS//-DPIC}" &&

# Default target, not detected correctly
OPTS="$OPTS -DLLVM_DEFAULT_TARGET_TRIPLE=$HOST" &&

# LLVM_targets and runtimes
OPTS="$OPTS -DLLVM_TARGETS_TO_BUILD=${LLVM_TARGETS// /;}" &&
OPTS="$OPTS -DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=${LLVM_EXPERIMENTAL_TARGETS// /;}" &&
OPTS="$OPTS -DLLVM_ENABLE_RUNTIMES=${LLVM_RUNTIMES// /;}" &&

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

if [[ "$LLVM_WITH_BOLT" == y ]] ;then
  LLVM_PROJECTS="$LLVM_PROJECTS bolt" &&
  OPTS="$OPTS -DLLVM_TOOL_BOLT_BUILD=ON"
fi &&

if [[ "$LLVM_WITH_CLANG" == y ]] ;then
  LLVM_PROJECTS="$LLVM_PROJECTS clang;clang-tools-extra" &&
  OPTS="$OPTS -DLLVM_TOOL_CLANG_TOOLS_EXTRA_BUILD=ON" &&
  OPTS="$OPTS -DCLANG_INCLUDE_BENCHMARKS=OFF" &&
  OPTS="$OPTS -DCLANG_INCLUDE_TESTS=OFF"
fi &&

if [[ "$LLVM_WITH_FLANG" == y ]] ;then
  LLVM_PROJECTS="$LLVM_PROJECTS flang"
fi &&

if [[ "$LLVM_WITH_LIBCLC" == y ]] ;then
  LLVM_PROJECTS="$LLVM_PROJECTS libclc" &&
  OPTS="$OPTS -DLIBCLC_TARGETS_TO_BUILD=${LLVM_LIBCLC_TARGETS// /;}"
fi &&

# workaround for https://github.com/llvm/llvm-project/issues/109537
if [[ "$LLVM_WITH_LIBCLC" == y ]] ;then
  OPTS="$OPTS -DLLVM_SPIRV=$(command -v llvm-spirv)"
fi &&

if [[ "$LLVM_WITH_LLD" == y ]] ;then
  LLVM_PROJECTS="$LLVM_PROJECTS lld" &&
  OPTS="$OPTS -DLLVM_TOOL_LLD_BUILD=ON"
fi &&

if [[ "$LLVM_WITH_LLDB" == y ]] ;then
  LLVM_PROJECTS="$LLVM_PROJECTS lldb" &&
  OPTS="$OPTS -DLLVM_TOOL_LLDB_BUILD=ON" &&
  OPTS="$OPTS -DLLDB_INCLUDE_TESTS=OFF"
fi &&

if [[ "$LLVM_WITH_MLIR" == y ]] ;then
  LLVM_PROJECTS="$LLVM_PROJECTS mlir" &&
  OPTS="$OPTS -DLLVM_TOOL_MLIR_BUILD=ON" &&
  OPTS="$OPTS -DMLIR_ENABLE_PYTHON_BENCHMARKS=OFF" &&
  if [[ "$LLVM_WITH_SPIRV" == y ]] ;then
    OPTS="$OPTS -DMLIR_ENABLE_SPIRV_CPU_RUNNER=ON"
  fi
fi &&

if [[ "$LLVM_WITH_POLLY" == y ]] ;then
  LLVM_PROJECTS="$LLVM_PROJECTS polly" &&
  OPTS="$OPTS -DLLVM_TOOL_POLLY_BUILD=ON"
fi &&

if [[ "$LLVM_WITH_SPIRV" == y ]] ;then
  OPTS="$OPTS -DLLVM_EXTERNAL_SPIRV_HEADERS_SOURCE_DIR=/usr/include/spirv" &&
  OPTS="$OPTS -DLLVM_TOOL_SPIRV_BUILD=ON"
fi &&

if [[ "$LLVM_WITH_UTILS" == y ]] ;then
  OPTS="$OPTS -DLLVM_BUILD_UTILS=ON"
  OPTS="$OPTS -DLLVM_INSTALL_UTILS=ON"
else
  OPTS="$OPTS -DLLVM_BUILD_UTILS=OFF"
  OPTS="$OPTS -DLLVM_INSTALL_UTILS=OFF"
fi &&

if list_find "$LLVM_RUNTIMES" "compiler-rt" ;then
  OPTS="$OPTS -DLLVM_TOOL_COMPILER_RT_BUILD=ON" &&
  OPTS="$OPTS -DCOMPILER_RT_INCLUDE_TESTS=OFF"
fi &&

if list_find "$LLVM_RUNTIMES" "libcxx" ;then
  OPTS="$OPTS -DLLVM_TOOL_LIBCXX_BUILD=ON" &&
  # libcxx includes benchmarks by default, which in turn depend on
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

if [ -n "$LLVM_TOOLCHAIN_COMPILER" ] ;then
  case "$LLVM_TOOLCHAIN_COMPILER" in
    clang)
      OPTS="$OPTS -DCMAKE_C_COMPILER=clang" &&
      OPTS="$OPTS -DCMAKE_CXX_COMPILER=clang++"
      ;;
    gcc)
      OPTS="$OPTS -DCMAKE_C_COMPILER=gcc" &&
      OPTS="$OPTS -DCMAKE_CXX_COMPILER=g++"
      ;;
  esac
fi

if [ -n "$LLVM_TOOLCHAIN_LINKER" ] ;then
  local linker="$LLVM_TOOLCHAIN_LINKER" &&
  case "$linker" in
    default)
      linker="SYSTEM"
      case "$(readlink -f "$(command -v ld)" | sed 's,^.*/,,')" in
        lld|ld*.lld) OPTS="$OPTS -DLLVM_ENABLE_LLD=ON" ;;
      esac
      ;;
    lld) OPTS="$OPTS -DLLVM_ENABLE_LLD=ON" ;;
  esac &&
  linker="$(echo "$linker" | tr [a-z] [A-Z])" &&
  OPTS="$OPTS -DCMAKE_LINKER_TYPE=$linker"
fi &&

if [ -n "$LLVM_EXTERNAL_PROJECTS" ] ;then
  OPTS="$OPTS -DLLVM_EXTERNAL_PROJECTS=${LLVM_EXTERNAL_PROJECTS// /;}"
fi &&

if [ -n "$LLVM_PROJECTS" ] ;then
  OPTS="$OPTS -DLLVM_ENABLE_PROJECTS=${LLVM_PROJECTS// /;}"
fi &&

cmake_build -S ../llvm
