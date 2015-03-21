# The build expects krb5 to supply the stuff, have to shove in
# libgssglue directly. I am really not sure what the proper way is,
# I'm just trying to fix the build for now.
if is_depends_enabled $SPELL libgssglue; then
  export CFLAGS="$CFLAGS $(pkg-config --cflags libgssglue)" &&
  export LIBS="$LIBS $(pkg-config --libs libgssglue)"
fi &&
default_build
