cmake -B build -S "${SOURCE_DIRECTORY}" \
      -DCMAKE_INSTALL_PREFIX="${INSTALL_ROOT}/usr" \
      -DBUILD_SHARED_LIBS=ON \
      -DBUILD_TESTING=OFF \
      -DNO_AFFINITY=ON \
      -DUSE_OPENMP=1 \
      -DNO_WARMUP=1 \
      -DTARGET=CORE2 \
      -DNUM_THREADS=64 \
      -DDYNAMIC_ARCH=ON &&
    
cmake --build build &&

cmake -B build64 -S "${SOURCE_DIRECTORY}" \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DBUILD_SHARED_LIBS=ON \
    -DBUILD_TESTING=OFF \
    -DNO_AFFINITY=ON \
    -DUSE_OPENMP=1 \
    -DNO_WARMUP=1 \
    -DTARGET=CORE2 \
    -DNUM_THREADS=64 \
    -DDYNAMIC_ARCH=ON \
    -DINTERFACE64=1 \ &&
    
cmake --build build64
