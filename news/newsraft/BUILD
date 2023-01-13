if spell_ok curl && is_version_less $(installed_version curl) 7.87.0; then
  CFLAGS+=" -DCURL_WRITEFUNC_ERROR=0xFFFFFFFF"
fi &&

local target="" &&

if ! is_depends_enabled ${SPELL} scdoc; then
  target="newsraft"
fi &&

make CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" $target
