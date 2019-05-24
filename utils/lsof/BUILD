cd  ${SPELL}_${VERSION}_src       &&
yes |  ./Configure  linux         &&
sedit 's/{MAKE} /&CC="${CC}" /' Makefile &&
make CC="$CC" DEBUG="$CFLAGS"
