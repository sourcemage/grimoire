./configure  --prefix=${INSTALL_ROOT}/usr                           \
             --sysconfdir=${INSTALL_ROOT}/etc                       \
             --localstatedir=${INSTALL_ROOT}/var                    \
             $OPTS                                                  &&

sedit  "s:CFLAGS = \-O2 \-Wall:CFLAGS = $CFLAGS:g"        Makefile  &&
sedit  "s:CXXFLAGS = \-O2 \-Wall:CXXFLAGS = $CXXFLAGS:g"  Makefile  &&

make
