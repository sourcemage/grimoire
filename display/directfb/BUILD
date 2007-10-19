if  [[  -f  /usr/include/linux/fusion.h  ]];  then
  OPTS="$OPTS --enable-multi"
fi  &&

OPTS="--with-inputdrivers=$inputdrivers         \
      --with-gfxdrivers=$gfxdrivers             \
      $DFB_DEBUG $DFB_NETWORK $DFB_VOODOO       \
      $DFB_UNIQUE $DFB_V4L $DFB_V4L2 $DFB_TESTS \
      $OPTS"                                    &&

#
## Remove this after is_depends_enabled is integrated to stable sorcery.
#
source  "$GRIMOIRE/is_depends_enabled.function"  &&

if is_depends_enabled $SPELL libmpeg3; then
     export CPPFLAGS="$CPPFLAGS -I/usr/include/libmpeg3/"
fi &&

default_build
