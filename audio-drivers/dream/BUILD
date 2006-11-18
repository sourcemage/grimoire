[ -f bootstrap ] && sh bootstrap
sed -i 's,$QTDIR/bin,/usr/bin,' configure &&
./configure $OPTS --prefix=$INSTALL_ROOT/usr --with-qtdir=/usr/include/qt --without-faad2 &&
make
