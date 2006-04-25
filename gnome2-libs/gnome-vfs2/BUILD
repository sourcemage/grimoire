if  [  "$IPV6"  ==  "y"  ];  then
   OPTS="--enable-IPV6  $OPTS"
fi  &&

if  [  "$GNOME_VFS_CRYPTO"  ==  "none"  ];  then
  OPTS="--disable-openssl  \
        --disable-gnutls   \
        $OPTS"
fi  &&

OPTS=$(echo $OPTS|sed 's!PMOUNT_ON!--with-hal-mount=\"/usr/bin/pmount-hal %h\" --with-hal-umount=\"/usr/bin/pumount %d\"!')

# Fix a simple Samba API name change; not using patch because of a single line
# See "http://websvn.samba.org/cgi-bin/viewcvs.cgi/branches/SAMBA_3_0_RELEASE/source/include/libsmbclient.h?rev=8329&r1=6369&r2=8329"
sedit 's|smb_context->close\>|smb_context->close_fn|g' modules/smb-method.c &&

eval "./configure --prefix=${INSTALL_ROOT}/usr             \
              --sysconfdir=${INSTALL_ROOT}/etc             \
           --localstatedir=${INSTALL_ROOT}/var             \
                  --mandir=${INSTALL_ROOT}/usr/share/man   \
                 --infodir=${INSTALL_ROOT}/usr/share/info  \
                       $OPTS"                              &&
make
