# this patch leads to a lot of warnings, but it doesn't compile without it
patch -p0 < $SCRIPT_DIRECTORY/avifile-fixes.patch  &&
# fix the pkgconfig file, avifile install header to include/avifile-0.7,
# not include/avifile
sedit  's:\(@includedir@/avifile\):\1-0.7:' avifile.pc.in  &&
# needed for xvid detection
LDFLAGS="$LDFLAGS -lm"  &&
default_build
