cd "${SOURCE_DIRECTORY}/perf" &&

local _targets="all" &&

if is_depends_enabled ${SPELL} asciidoc; then
  _targets="all man"
fi &&

make CFLAGS="${CFLAGS}" EXTRA_CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
     V=1 WERROR=0 DESTDIR="${INSTALL_ROOT}" prefix=/usr lib=lib/perf \
     plugindir_SQ="${INSTALL_ROOT}/usr/lib/traceevent/plugins" \
     ${OPTS} $_targets
