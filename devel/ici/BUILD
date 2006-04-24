#sed -i "s/-ltermcap//;s|/local||;s|/tmp||;s|/usr/man|/usr/share/man|" 
sed -i "s/-ltermcap//;;s|)/man|)/share/man|" \
       Makefile.linux  &&
make -f Makefile.linux PREFIX=/usr
