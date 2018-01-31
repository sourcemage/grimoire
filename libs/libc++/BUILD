CXXFLAGS="-std=c++11 ${CXXFLAGS}" &&

OPTS="-DCMAKE_C_COMPILER=clang \
      -DCMAKE_CXX_COMPILER=clang++ \
      ${OPTS}" &&

persistent_add ABI_DIR &&

ABI_DIR="${SPELLX}abi-${VERSION}.src" &&

cd "${ABI_DIR}" &&

ABI_OPTS="-DLIBCXXABI_LIBCXX_INCLUDES=../../include ${OPTS}" &&

OPTS="${ABI_OPTS}" cmake_build &&

cd ../.. &&

LDFLAGS="-L${SOURCE_DIRECTORY}/${ABI_DIR}/build/lib ${LDFLAGS}" &&

OPTS="-DLIBCXX_CXX_ABI=libcxxabi \
      -DLIBCXX_LIBCXXABI_INCLUDE_PATHS=${SOURCE_DIRECTORY}/${ABI_DIR}/include \
      ${OPTS}" &&

cmake_build
