# remove APR and APU and reconfigure to use external ones
rm  -fr  srclib/apr*/  &&

# use smgl standard layout
cp -f $SCRIPT_DIRECTORY/config.layout $SOURCE_DIRECTORY &&

./buildconf  --with-apr=/usr/share/apache2         \
             --with-apr-util=/usr/share/apache2    &&

./configure  --prefix=$INSTALL_ROOT/usr            \
         --sysconfdir=$INSTALL_ROOT/etc/httpd      \
      --localstatedir=$INSTALL_ROOT/var            \
             --mandir=$INSTALL_ROOT/usr/share/man  \
      --enable-layout=SMGL                         \
     --enable-modules=most                         \
                      $OPTS $APACHE22_EXTRA        &&
make
