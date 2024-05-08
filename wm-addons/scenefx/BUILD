if ! is_depends_enabled $SPELL xwayland; then
  OPTS="xwayland=disabled $OPTS"
fi &&

OPTS="werror=false ${SCENEFX_OPTS} \
      renderers=${SCENEFX_RENDERERS// /,} \
      backends=${SCENEFX_BACKENDS// /,} \
      ${OPTS}" &&

default_build
