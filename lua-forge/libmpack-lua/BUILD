local LUAVER &&
if is_depends_enabled $SPELL luajit; then
  MPACK_LUA_VERSION=5.1.0 &&
  LUA_IMPL=luajit
else
  MPACK_LUA_VERSION="$(installed_version lua)" &&
  LUA_IMPL=lua-${MPACK_LUA_VERSION}
fi &&

make MPACK_LUA_VERSION="${MPACK_LUA_VERSION}" \
     LUA_IMPL="$LUA_IMPL" \
     USE_SYSTEM_LUA=yes \
     USE_SYSTEM_MPACK=yes
