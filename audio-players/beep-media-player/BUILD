if [ "$CVS" = "y" ]; then
   ./autogen.sh -n $OPTS
fi &&

if [ "$ONEPLUGINDIR" = "y" ]; then
   OPTS="$OPTS --enable-one-plugin-dir"
fi &&

if [ "$USERPLUGINDIR" = "n" ]; then
   OPTS="$OPTS --disable-user-plugin-dir"
fi &&

if [ "$OSS" = "n" ]; then
   OPTS="$OPTS --disable-oss"
fi &&

if [ "$SIMD" = "y" ]; then
   OPTS="$OPTS --enable-simd"
fi &&

# bug #14584
CFLAGS="$CFLAGS -O2" &&

default_build
