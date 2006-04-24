(

  ./autogen.sh                &&
  ./configure                 \
    --build=$BUILD            \
    --prefix=/usr             \
    --sysconfdir=/etc         \
    --localstatedir=/var      \
    --disable-maintainer-mode \
    $OPTS                     &&

  make            &&
  prepare_install &&
  make    install

) > $C_FIFO 2>&1
