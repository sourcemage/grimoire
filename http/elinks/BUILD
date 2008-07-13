if [[ $ELINKS_VCS == y ]]; then
  ./autogen.sh
fi &&

OPTS="--enable-exmode \
      --enable-fastmem \
      --enable-html-highlight \
      --enable-leds \
      --without-gnutls \
      $ELINKS_OPTS $OPTS" &&

make_single &&
default_build &&
make_normal
