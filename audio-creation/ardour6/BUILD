OPTS="--noconfirm \
      --configdir=$INSTALL_ROOT/etc \
      --optimize \
      --with-backends=$(echo "$ARDOUR6_AUDIO" | tr ' ' ,) \
      $ARDOUR6_OPTS \
      $OPTS" &&
waf_build
