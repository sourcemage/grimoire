case "$HOST" in
  (*-musl)
    OPTS+=' -DLIBCXX_HAS_MUSL_LIBC=YES'
    ;;
esac &&

# Remove -DPIC from compiler flags, produces build errors
CXXFLAGS="${CXXFLAGS//-DPIC}" &&

# Default target, not detected correctly
OPTS+=" -DLLVM_DEFAULT_TARGET_TRIPLE=$HOST" &&

# Targets and runtimes
OPTS+=" -DLLVM_TARGETS_TO_BUILD=${LLVM_TARGETS// /;}" &&

# recommended by mesa project
OPTS+=" -DLLVM_LINK_LLVM_DYLIB=1 -DCMAKE_BUILD_TYPE=RELEASE" &&

OPTS+=" -DLLVM_BUILD_BENCHMARKS=OFF" &&
OPTS+=" -DLLVM_INCLUDE_BENCHMARKS=OFF" &&
OPTS+=" -DLLVM_INCLUDE_TESTS=OFF" &&

# prevent unnecessary use of libedit and ncurses
OPTS+=" -DLLVM_ENABLE_LIBEDIT=OFF" &&
OPTS+=" -DLLVM_ENABLE_TERMINFO=OFF" &&
OPTS+=" -DLLVM_ENABLE_BACKTRACES=OFF"

# Enable RTTI if requested, recommended, changing it breaks the ABI
if [[ y == "$LLVM_WITH_RTTI" ]]; then
  OPTS+=" -DLLVM_ENABLE_RTTI=ON"
else
  OPTS+=" -DLLVM_ENABLE_RTTI=OFF"
fi &&


cmake_build "${INSTALL_ROOT}/opt/$SPELL"
