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
