sed -i -e 's:PREFIX = /usr/local:PREFIX = '${D}'/usr:g' Makefile
sed -i -e 's:GTK_PREFIX = $(PREFIX):GTK_PREFIX = /usr:g' Makefile
sed -i -e 's:GAIM_TOP = ../gaim:GAIM_TOP = /usr/include/gaim:g' Makefile
sedit  '44i-I$(GTK_PREFIX)/include/cairo \\'  Makefile

make_single  &&
make         &&
make_normal
