# fix so pkg-config still looks in /usr/lib/pkgconfig instead of
# /usr/lib/pkg-config
sedit 's:$libdir/$PACKAGE:$libdir/pkgconfig:'    configure.in  &&
sedit 's:$datadir/$PACKAGE:$datadir/pkgconfig:'  configure.in  &&

aclocal         &&
autoconf        &&
cd  glib-1.2.8  &&
aclocal         &&
autoconf        &&
cd  ..          &&
default_build
