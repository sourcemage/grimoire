DEFAULT_CFLAGS="CFLAGS    = -O3 -fomit-frame-pointer -Wall"  &&
     SA_CFLAGS="CFLAGS    = $CFLAGS  -Wall"                  &&

sedit  "s/$DEFAULT_CFLAGS/$SA_CFLAGS/"  Makefile.rules       &&

default_build
#./configure  --build=$BUILD        \
#             --prefix=/usr         \
#             --sysconfdir=/etc     \
#             --localstatedir=/var  \
#             $OPTS                 &&
#make                               &&
