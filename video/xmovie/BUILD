invoke_gcc
patch -p1 < $SCRIPT_DIRECTORY/xmovie-shared.patch  &&
patch -p0 < $SCRIPT_DIRECTORY/xmovie-fixes.patch   &&

( echo $CFLAGS | grep -q -- "-O." ) || CFLAGS="$CFLAGS -O2"  &&
make
