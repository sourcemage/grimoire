if list_find $XLOCKMORE_BO "--enable-blank-only"; then
  OPTS="--without-opengl \
        --without-mesa \
        --without-freetype \
        $OPTS"
fi &&

OPTS="$XLOCKMORE_BO $OPTS"

make_single &&
default_build &&
make_normal
