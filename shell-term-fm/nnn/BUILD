export LDLIBS= &&
if is_depends_enabled "$SPELL" musl-fts; then
  LDLIBS+=' -lfts'
fi &&

OPTS="${NNN_OPTS} ${OPTS}" &&

make CFLAGS_OPTIMIZATION= $OPTS
