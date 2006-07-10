echo  "gcc ${CFLAGS}"  >  conf-cc  &&
echo  "gcc -g -L. $LDFLAGS"     >  conf-ld  &&
echo  "$INSTALL_ROOT/usr/share/man" > conf-man &&
sedit "s:/usr/local:$INSTALL_ROOT/usr:" conf-bin &&
sedit "s:/usr/local/bglibs/lib:$INSTALL_ROOT/usr/lib/bglibs:" conf-lib &&
sedit "s:/usr/local/bglibs/include:$INSTALL_ROOT/usr/include/bglibs:" conf-include &&
make
