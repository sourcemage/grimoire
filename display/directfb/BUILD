OPTS="--with-inputdrivers=$inputdrivers         \
      --with-gfxdrivers=$gfxdrivers             \
      --disable-vnc                             \
      $DFB_DEBUG $DFB_NETWORK $DFB_VOODOO       \
      $DFB_UNIQUE $DFB_V4L $DFB_V4L2 $DFB_TESTS \
      $OPTS"                                    &&


if is_depends_enabled $SPELL libmpeg3; then
     export CPPFLAGS="$CPPFLAGS -I/usr/include/libmpeg3/"
fi &&

default_build
