OPTS="--noconfirm \
      --configdir=$INSTALL_ROOT/etc \
      --optimize \
      --with-backends=$(echo "$ARDOUR4_AUDIO" | tr ' ' ,) \
      $ARDOUR4_OPTS \
      $OPTS" &&

waf_build
