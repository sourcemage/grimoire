./configure  --build=$BUILD        		    \
             --prefix=${INSTALL_ROOT}/usr         \
             --sysconfdir=${INSTALL_ROOT}/etc     \
             --localstatedir=${INSTALL_ROOT}/var  \
             --with-ggi-driver=no                 \
             $OPTS  &&

sedit "s/"cx"/"dx"/g" src/engine/i386.c  &&
sedit "s/penium/pentium/" src/engine/i386.c  &&

make  all
