if [[ $ELINKS_BRANCH == scm ]]; then
  ./autogen.sh
fi &&

OPTS="--enable-exmode \
      --enable-fastmem \
      --enable-html-highlight \
      --enable-leds \
      --without-gnutls \
      $ELINKS_OPTS $OPTS" &&

# enable verbose build mode
export V=1 &&

make_single &&
default_build &&
make_normal
