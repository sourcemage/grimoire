#for opentracker to build, libowfat needs to be compiled with gcc,
#not with diet, so easy way out atm is to dispel dietlibc 
#if necessary and recast libowfat without it. Beats me.

sed -i -r 's:^# (.*/opt/diet):\1:' Makefile &&
sed -i -r \
's:^# (LIBOWFAT_HEADERS=\$\(PREFIX\)/include$):\1:' \
Makefile &&
sed -i -r \
's:^# (LIBOWFAT_LIBRARY=\$\(PREFIX\)/lib$):\1:' \
Makefile &&

sed -i -r 's:^(PREFIX\?=\.\.):#\1:' Makefile &&
sed -i -r \
's:^(LIBOWFAT_HEADERS=\$\(PREFIX\)/libowfat):#\1:' \
Makefile &&
sed -i -r \
's:^(LIBOWFAT_LIBRARY=\$\(PREFIX\)/libowfat):#\1:' \
Makefile &&

#works for me. getting an error about ip6 address otherwise.
#reported upstream.
sed -i -r \
's:^#(FEATURES\+=-DWANT_BROKEN_OPENBSD_V6_API$):\1:' \
Makefile &&

make
