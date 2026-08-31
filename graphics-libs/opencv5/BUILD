CXXFLAGS=-D__STDC_CONSTANT_MACROS &&
OPTS+=" -DENABLE_CCACHE=OFF" &&
OPTS+=" -DCMAKE_BUILD_TYPE=Release -DBUILD_DOCS=0 -DBUILD_PERF_TESTS=0 \
  -DBUILD_TESTS=0 -Wno-dev" &&
OPTS+=' -DOPENCV_FORCE_3RDPARTY_BUILD=0' &&
CONTRIB=''

if [[ $CV_CONTRIB_A_N != none ]];then
  CONTRIB+="$CV_CONTRIB_A_N"
fi &&
if [[ $CV_CONTRIB_O_Z != none ]];then
  CONTRIB+=" $CV_CONTRIB_O_Z"
fi
if [[ $CV_CONTRIB_CUDA != none ]];then
  CONTRIB+=" $CV_CONTRIB_CUDA"
fi


if [[ $CONTRIB != none ]];then
 OPTS+=" -DOPENCV_EXTRA_MODULES_PATH=$SOURCE_DIRECTORY/contrib"
fi &&

OPTS+=" -DIPPROOT=$SOURCE_DIRECTORY/ippicv_lnx" &&

# PCH fails, at least with, with GCC 6.2
#OPTS+=" -DENABLE_PRECOMPILED_HEADERS=0" &&
cmake_build
