OPTS="--enable-shared  $PYTHON3_OPTS $OPTS" &&
OPTS="--with-ensurepip=no $OPTS"            &&

OPTS+=" --enable-optimizations"             &&
OPTS+=" --with-lto"                         &&
OPTS+=" --with-computed-gotos"              &&

OPTS="$OPTS --build=${BUILD}"

[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

EXTRA_CFLAGS="$CFLAGS" ./configure --prefix=${INSTALL_ROOT}/usr  \
        --sysconfdir=${INSTALL_ROOT}/etc  \
     --localstatedir=${INSTALL_ROOT}/var  \
            --mandir=${INSTALL_ROOT}/usr/share/man   \
           --infodir=${INSTALL_ROOT}/usr/share/info  \
                     $OPTS                 &&

if ! is_depends_enabled $SPELL libxcrypt; then
  sed -i -e 's/MODULE__CRYPT_STATE=.*/MODULE__CRYPT_STATE=disabled/' \
         -e 's/MODULE__CRYPT_CFLAGS=.*/MODULE__CRYPT_CFLAGS=/' \
         -e 's/MODULE__CRYPT_LDFLAGS=.*/MODULE__CRYPT_LDFLAGS=/' \
         Makefile
fi &&

EXTRA_CFLAGS="$CFLAGS" make
