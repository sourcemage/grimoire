OPTS="$OPTS $CONKY_OPTS" &&

if is_depends_enabled ${SPELL} $(get_spell_provider ${SPELL} LUA); then
  LDFLAGS="-ltoluapp ${LDFLAGS}"
fi &&

default_build
