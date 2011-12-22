# use user-specific worker
APACHE22_EXTRA="${APACHE22_EXTRA} --with-mpm=${APACHE22_MPM}" &&

# remove APR and APU and reconfigure to use external ones
rm  -fr  srclib/apr*/  &&

# correct flags to find external apr-util
CPPFLAGS="`apr-config --includes` $CPPFLAGS" &&

# use smgl standard layout
cp -f $SCRIPT_DIRECTORY/config.layout $SOURCE_DIRECTORY &&

./configure  --prefix=$INSTALL_ROOT/usr            \
        --exec_prefix=$INSTALL_ROOT/usr            \
             --bindir=$INSTALL_ROOT/usr/bin        \
            --sbindir=$INSTALL_ROOT/usr/sbin       \
         --sysconfdir=$INSTALL_ROOT/etc/httpd      \
      --localstatedir=$INSTALL_ROOT/var            \
             --mandir=$INSTALL_ROOT/usr/share/man  \
      --enable-layout=SMGL                         \
          --enable-so                              \
                      $OPTS $APACHE22_EXTRA        &&
make
