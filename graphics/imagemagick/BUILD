if [[ "$IMAGEMAGICK_X" != "y" ]]; then
  OPTS="--without-x $OPTS"
fi &&

OPTS="--enable-shared \
      --without-autotrace \
      $IMAGEMAGICK_HDRI \
      $OPTS" &&
default_build
