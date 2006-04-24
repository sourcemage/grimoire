(

  ./configure  --build=$BUILD              \
               --prefix=/usr               \
               --sysconfdir=/etc           \
               --localstatedir=/var        \
               --with-gd-lib               \
			   --with-z-lib                \
			   --with-png-lib              \
			   --with-jpeg-lib             \
			   --with-freetype2-lib        \
               $OPTS                       &&
  make                                     &&
  prepare_install                          &&
  cp  -f  cvsgraph  /usr/bin/

) > $C_FIFO 2>&1
