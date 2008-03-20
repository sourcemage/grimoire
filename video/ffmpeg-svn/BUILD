CFLAGS="${CFLAGS/-funroll-loops/} -O3"
disable_pic  &&

#if [ $FFAMR != none ];then
#  OPTS="--enable-lib$FFAMR $FFMPEG_SWSCALE $OPTS"
#fi  &&

OPTS="$FFMPEG_SWSCALE $OPTS"  &&

./configure  --prefix=${INSTALL_ROOT}/usr            \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             --incdir=${INSTALL_ROOT}/usr/include/ffmpeg \
             --enable-shared                         \
             --enable-pthreads                       \
             --disable-static                        \
             --disable-debug                         \
             --enable-postproc                       \
             --enable-gpl                            \
             $OPTS                         &&
#sedit  's:SDL_LIBS=.*:\0 -L/usr/X11R6/lib -lX11:'  config.mak  &&
make
