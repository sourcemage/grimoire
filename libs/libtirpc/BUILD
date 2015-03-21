# Doesn't find gssglue headers by itself.
if is_depends_enabled $SPELL libgssglue; then
  export CPPFLAGS="$CPPFLAGS -I$INSTALL_ROOT/usr/include/gssglue"
fi &&
default_build
