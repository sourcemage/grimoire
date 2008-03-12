unpack_file 2                                &&
zcat   $SOURCE2                  | patch -p1 &&
cat    $SCRIPT_DIRECTORY/ncompress-gcc34.patch | patch -p1 &&
export LBOPT="$CFLAGS $LDFLAGS"  &&
sed -e 's/LBOPT=//' Makefile.def > Makefile &&
make
