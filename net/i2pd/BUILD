. "${GRIMOIRE}/FUNCTIONS" &&

OPTS="${I2PD_OPTS} ${OPTS}" &&

if spell_ok gcc && is_version_less $(installed_version gcc) 4.7; then
  LDFLAGS="-lboost_chrono ${LDFLAGS}"
fi &&

cd build &&
prepare_cmake_flags &&
cmake -DCMAKE_INSTALL_PREFIX=${INSTALL_ROOT}/usr \
  -DCMAKE_INSTALL_SYSCONFDIR=${INSTALL_ROOT}/etc \
         -DBUILD_SHARED_LIBS=ON \
      -DCMAKE_INSTALL_LIBDIR=lib \
      -DCMAKE_INSTALL_BINDIR=sbin \
          -DCMAKE_BUILD_TYPE=${CM_BUILD_TYPE} \
     -DCMAKE_C_FLAGS_RELEASE="${CFLAGS}" \
   -DCMAKE_CXX_FLAGS_RELEASE="${CXXFLAGS}" \
                             ${OPTS} .  &&
cmake --build .
