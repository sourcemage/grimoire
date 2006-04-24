./configure  --build=$BUILD        \
             --prefix=/usr         \
             --sysconfdir=/etc     \
             --localstatedir=/var  \
             $OPTS                 &&

sedit  "s:CFLAGS = -g -O0 :CFLAGS = ${CFLAGS} -g :"  Makefile  &&

make
