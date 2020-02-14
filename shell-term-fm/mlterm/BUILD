TEXT_RENDERERS="xcore" &&
if is_depends_enabled $SPELL libxft; then
  TEXT_RENDERERS+=",xft"
fi &&
if is_depends_enabled $SPELL cairo; then
  TEXT_RENDERERS+=",cairo"
fi &&

OPTS+=" --with-type-engines=$TEXT_RENDERERS" &&

OPTS+=" --enable-optimize-redrawing" &&

default_build
