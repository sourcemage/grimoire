unpack $SOURCE2                    ${MD5[1]} &&
zcat   $SOURCE2                  | patch -p1 &&
cat    $SCRIPT_DIRECTORY/ncompress-gcc34.patch | patch -p1 &&
export LBOPT="$CFLAGS $LDFLAGS"  &&
sed -e 's/LBOPT=//' Makefile.def > Makefile &&
make
