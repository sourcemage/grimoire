cat "$SOURCE_CACHE/$SOURCE" | sed "s:luaL_reg:luaL_Reg:g" | \
    gcc -Wall $CFLAGS -I$INSTALL_ROOT/usr/include \
                      -I$INSTALL_ROOT/usr/include/libxml2 \
                      -c -xc - -o luaxslt.o &&

gcc -shared $LDFLAGS -o luaxsltlib.so -llua -lm -ldl -lxslt -lxml2 -lz -lpthread luaxslt.o
