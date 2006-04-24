
echo "gcc ${CFLAGS}" >conf-cc &&
echo "gcc -g -L." >conf-ld    &&
sedit "s:/usr/local:$INSTALL_ROOT/usr:" conf-bin &&
sedit "s:/usr/local/bglibs/lib:$INSTALL_ROOT/usr/lib/bglibs:" conf-lib &&
sedit "s:/usr/local/bglibs/include:$INSTALL_ROOT/usr/include/bglibs:" conf-include &&
make -j1

