OPTS="--with-swatdir=/usr/share/swat  \
      --with-fhs                      \
      --with-automount                \
      --with-winbind                  \
      --with-libsmbclient             \
      $SAMBA_QUOTA                    \
      $OPTS"                          &&

cd  $SOURCE_DIRECTORY/source3  &&
default_build  &&

if [[ "$SAMBA_VSCAN" == "y" ]] ; then
        ORG_DIR=`pwd`
        cd $SOURCE_DIRECTORY/examples/VFS/$SPELL-vscan-$VSCAN_VERSION &&
        ./configure $ORG_OPTS   &&
        make &&
        cd $ORG_DIR
fi
