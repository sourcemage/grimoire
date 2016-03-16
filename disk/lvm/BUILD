./configure --build=$BUILD                  		\
            --prefix=$INSTALL_ROOT/usr      		\
            --sbindir=$INSTALL_ROOT/sbin    		\
            --libdir=$INSTALL_ROOT/lib      		\
            --sysconfdir=$INSTALL_ROOT/etc  		\
            --mandir=$INSTALL_ROOT/usr/share/man 	\
            --enable-static_link              		\
            $LVM_OPTS $OPTS                             &&
make_single &&

if [[ $LVM_DM_ONLY == y ]]; then
  make device-mapper
else
  make
fi &&

make_normal
