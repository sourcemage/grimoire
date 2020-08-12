# Remove -DPIC from compiler flags, produces build errors
CXXFLAGS="${CXXFLAGS//-DPIC}" &&
# Default target, not detected correctly
OPTS+=" -DLLVM_DEFAULT_TARGET_TRIPLE=$HOST" &&
# LLVM_TARGETS
OPTS+=" -DLLVM_TARGETS_TO_BUILD=${LLVM_TARGETS// /;}" &&
# recommended by mesa project
OPTS+=" -DLLVM_LINK_LLVM_DYLIB=1 -DCMAKE_BUILD_TYPE=RELEASE" &&
# use modern c++ features
OPTS+=" -DLLVM_ENABLE_CXX1Y=1 -DLLVM_ENABLE_CXX1Z=1 " &&
# prevent unnecessary use of libedit and ncurses
if ! is_depends_enabled $SPELL libedit;then
  OPTS+=" -DLLVM_ENABLE_LIBEDIT=0" &&
  OPTS+=" -DLLVM_ENABLE_TERMINFO=0" &&
  OPTS+=" -DLLVM_ENABLE_BACKTRACES=0"
fi &&

message opts=$OPTS &&
cmake_build
