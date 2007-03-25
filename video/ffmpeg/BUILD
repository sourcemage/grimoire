CFLAGS="${CFLAGS/-funroll-loops/} -O3"
disable_pic  &&

if [ $FFAMR != none ];then
  OPTS="--enable-$FFAMR $OPTS"
fi  &&

./configure  --prefix=${INSTALL_ROOT}/usr            \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             --enable-shared                         \
             --enable-pthreads                       \
             --disable-static                        \
             --disable-debug                         \
             --enable-pp                             \
	     --enable-swscaler                       \
             --enable-gpl                            \
             $OPTS                         &&
make
