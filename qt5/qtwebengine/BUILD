#CFLAGS="${CFLAGS/-ffast-math}" &&
#CFLAGS=''  &&
# This was mistyped, and why should we remove our flags?
#CXXFLAGS='' &&
OPTS+=" -shared"  &&
if list_find "$CXXFLAGS" -Os; then
  OPTS+=" -optimize-size"
fi &&
default_build
