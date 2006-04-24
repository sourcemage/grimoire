#  patch -p1 < $SCRIPT_DIRECTORY/Makefile.diff &&

  ./buildconf --with-apr=/usr/share/apache2 &&

  ./configure \
    --host=$HOST \
    --build=$BUILD \
    --prefix=/usr \
    --includedir=/usr/include/apr \
    --sysconfdir=/etc \
    --localstatedir=/var \
    --enable-layout=GNU \
    $OPTS &&
  make
