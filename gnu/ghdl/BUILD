OPTS="${OPTS} --prefix=${INSTALL_ROOT}/opt/${SPELL}-${VERSION}" &&
OPTS="${OPTS} --disable-libada"                                 &&
OPTS="${OPTS} --enable-threads=posix"                           &&
OPTS="${OPTS} --disable-bootstrap"                              &&
OPTS="${OPTS} --enable-clocale=gnu"                             &&
if [[ $CROSS_INSTALL == on ]]; then
  OPTS="--host=$HOST $OPTS"
else
  OPTS="--build=$HOST $OPTS"
fi  &&
cd ${SOURCE_DIRECTORY}/build &&
../src/configure --enable-languages="vhdl" ${OPTS} &&
make_single                                        &&
make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" &&
make_normal
