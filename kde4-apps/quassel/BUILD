OPTS="$OPTS -DLINGUAS=\"$QUAS_LING\"" &&
#message o=$OPTS &&
if is_depends_enabled $SPELL kdebase4-runtime;then
  default_build
else
  qt4_cmake_build
fi
