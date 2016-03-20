if is_depends_enabled $SPELL cairo; then
  CFLAGS="-lX11 $CFLAGS" &&
  CXXFLAGS="-lX11 $CXXFLAGS"
fi &&
if is_depends_enabled $SPELL $(get_spell_provider $SPELL OPENGL); then
  CFLAGS="-lGL $CFLAGS" &&
  CXXFLAGS="-lGL $CXXFLAGS"
fi &&
LDFLAGS="-pthread $LDFLAGS" \
  CFLAGS="-pthread $CFLAGS" \
  CXXFLAGS="-pthread $CXXFLAGS" default_build
