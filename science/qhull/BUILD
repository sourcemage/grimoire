cd src &&

sedit  "s:BINDIR  = /usr/local/bin:BINDIR  = \${INSTALL_ROOT}/usr/bin:" Makefile &&
sedit  "s:MANDIR  = /usr/local/man/man1:MANDIR  = \${INSTALL_ROOT}/usr/share/man/man1:" Makefile &&

echo "libqhull.so: \$(OBJS)" >> Makefile &&
echo "	c++ -shared -Xlinker -soname -Xlinker \$@ -o libqhull.so \$(OBJS)" >> Makefile &&

make &&
make libqhull.so

# Problem with cups and lpr, to be fixed later...
#make doc

