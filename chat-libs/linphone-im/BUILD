LDFLAGS="$LDFLAGS -L$SOURCE_DIRECTORY/speex/libspeex/.libs" &&

if [[ "$CROSS_INSTALL" == on ]]; then
  OPTS="$OPTS --host=${HOST} --build=${BUILD}"
fi &&
invoke_gcc &&
./configure --prefix=${INSTALL_ROOT}/usr  \
        --sysconfdir=${INSTALL_ROOT}/etc  \
     --localstatedir=${INSTALL_ROOT}/var  \
            --mandir=${INSTALL_ROOT}/usr/share/man   \
           --infodir=${INSTALL_ROOT}/usr/share/info  \
                     $OPTS                 &&
cd libr263 &&
sedit "s|CFLAGS\\s*=|\\0 $CFLAGS|g" Makefile &&
make library &&
cd ../speex &&
make &&
cd .. &&
make
