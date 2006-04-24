CFLAGS="${CFLAGS} -g -Wall -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE" &&
patch -p0 < $SCRIPT_DIRECTORY/makefile.patch       &&
patch -p0 < $SCRIPT_DIRECTORY/replex-fixes.patch   &&
sedit "s:/usr/local:$INSTALL_ROOT/usr:"  Makefile  &&
make_single                                        &&
make                                               &&
make_normal
