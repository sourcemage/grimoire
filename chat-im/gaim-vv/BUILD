# [[ $CROSS_INSTALL == on ]] &&
#  OPTS="$OPTS --host=${HOST} --build=${BUILD}"

if  spell_ok  nss ; then
  export PKG_CONFIG_PATH="/usr/include/nss:/usr/include/nspr"
fi &&                

./configure --prefix=${INSTALL_ROOT}/usr  \
            --sysconfdir=${INSTALL_ROOT}/etc  \
            --localstatedir=${INSTALL_ROOT}/var  \
            --mandir=${INSTALL_ROOT}/usr/share/man   \
            --infodir=${INSTALL_ROOT}/usr/share/info  \
            --with-libj2k=/usr  \
            --enable-linphone  \
            --with-linphone-prefix=/usr  \
            --enable-msn-vv   \
	    $OPTS                 &&

make
