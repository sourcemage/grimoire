# "PIC" is used as an identifier
CXXFLAGS="${CXXFLAGS/-DPIC }" &&
# LLVM_TARGETS
OPTS+=" -DLLVM_TARGETS_TO_BUILD=`echo ${LLVM_TARGETS} | sed 's/ /;/g'`" &&
# Not restricting targets, so that mesalib gets R600.
#if [[ $LLVM_EXP_R600 == y   ]];then
#  OPTS+=" -DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=R600"
#fi &&
OPTS+=" -DBUILD_SHARED_LIBS=1 -DCMAKE_BUILD_TYPE=RELEASE" &&
message opts=$OPTS &&
cmake_build
