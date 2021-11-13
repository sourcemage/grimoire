if [[ "${NGTCP2_WITHSSL}" == "y" ]]; then
  cd "${SOURCE_DIRECTORY}/openssl" &&
  ./config enable-tls1_3 no-shared --prefix="${SOURCE_DIRECTORY}/openssl/build" &&
  make -j${MAKE_NJOBS:-1} &&
  make -j${MAKE_NJOBS:-1} install_sw &&
  OPTS+=" --with-openssl" &&
  export OPENSSL_CFLAGS="-I${SOURCE_DIRECTORY}/openssl/build/include" &&
  export OPENSSL_LIBS="-pthread -Wl,--whole-archive -ldl -lpthread -lrt ${SOURCE_DIRECTORY}/openssl/build/lib/libssl.a ${SOURCE_DIRECTORY}/openssl/build/lib/libcrypto.a -Wl,--no-whole-archive" &&
  cd "${SOURCE_DIRECTORY}"
fi &&
default_build
