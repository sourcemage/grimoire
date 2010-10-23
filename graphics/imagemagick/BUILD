if [[ "$IMAGEMAGICK_X" != "y" ]]; then
  OPTS="--without-x $OPTS"
fi &&

# GS is broken with jpeg 8, so disable it
OPTS="--enable-shared \
      --without-autotrace \
      --without-gslib \
      $IMAGEMAGICK_HDRI \
      $OPTS" &&
default_build
