if ! is_depends_enabled $SPELL xwayland; then
  OPTS="xwayland=disabled $OPTS"
fi &&

OPTS="werror=false ${WLROOTS_OPTS} \
      renderers=${WLROOTS_RENDERERS// /,} \
      backends=${WLROOTS_BACKENDS// /,} \
      ${OPTS}" &&

default_build
