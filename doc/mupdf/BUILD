if is_depends_enabled ${SPELL} $(get_spell_provider ${SPELL} OPENGL); then
  LDFLAGS="-lglfw -lGL ${LDFLAGS}"
fi &&

CFLAGS= LIBS= make XCFLAGS="$CFLAGS" XLIBS="$LDFLAGS" ${OPTS} build=release verbose=yes USE_SYSTEM_LIBS=yes
