case "$HOST" in
  (*-musl)
    OPTS+=' -DLIBCXX_HAS_MUSL_LIBC=YES'
    ;;
esac &&
# Remove -DPIC from compiler flags, produces build errors
CXXFLAGS="${CXXFLAGS//-DPIC}" &&
# Default target, not detected correctly
OPTS+=" -DLLVM_DEFAULT_TARGET_TRIPLE=$HOST" &&
# LLVM_TARGETS
OPTS+=" -DLLVM_TARGETS_TO_BUILD=${LLVM_TARGETS// /;}" &&
# recommended by mesa project
OPTS+=" -DLLVM_LINK_LLVM_DYLIB=1 -DCMAKE_BUILD_TYPE=RELEASE" &&
# prevent unnecessary use of libedit and ncurses
if ! is_depends_enabled $SPELL libedit;then
  OPTS+=" -DLLVM_ENABLE_LIBEDIT=0" &&
  OPTS+=" -DLLVM_ENABLE_TERMINFO=0" &&
  OPTS+=" -DLLVM_ENABLE_BACKTRACES=0"
fi &&
# Enable RTTI if requested, recommended, changing it breaks the ABI
if [ y = "$LLVM_WITH_RTTI" ]; then
  OPTS+=" -DLLVM_ENABLE_RTTI=1"
else
  OPTS+=" -DLLVM_ENABLE_RTTI=0"
fi &&

OPTS+=" -DLLVM_BUILD_BENCHMARKS=OFF -DLLVM_INCLUDE_BENCHMARKS=OFF -DLLVM_INCLUDE_TESTS=OFF" &&

cmake_build
