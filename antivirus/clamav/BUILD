create_account clamav &&

OPTS="${CLAM_EXP} ${CLAM_IP6} $OPTS"   &&

if is_depends_enabled $SPELL musl-fts; then
  LDFLAGS+=" -lfts"
fi  &&

default_build
