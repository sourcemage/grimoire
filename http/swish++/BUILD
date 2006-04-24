# patch configuration and build system
patch  -p1  <  $SCRIPT_DIRECTORY/$SPELL.diff  &&

# switch to GCC 3.4 manually, GCC_VERSION in DETAILS doesn't work
invoke_gcc &&

make_single  &&
make         &&
make_normal
