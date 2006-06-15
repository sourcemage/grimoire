OPTS="--with-swatdir=/usr/share/swat  \
      --with-smbmount                 \
      --with-fhs                      \
      --with-automount                \
      --with-winbind                  \
      --with-libsmbclient             \
      $SAMBA_QUOTA                    \
      $OPTS"                          &&

pushd  source  &&
make_single    &&
default_build  &&

if  [  "$SAMBA_CIFS"  ==  "y"  ];  then
  gcc  $CFLAGS  $LDFLAGS  client/mount.cifs.c  \
       -o  client/mount.cifs
fi

if [ "$SAMBA_VSCAN" == "y" ] ; then
        ORG_DIR=`pwd`
        cd $SOURCE_DIRECTORY/examples/VFS/$SPELL-vscan-$VSCAN_VERSION &&
        ./configure $ORG_OPTS   &&
        make &&
        cd $ORG_DIR
fi


