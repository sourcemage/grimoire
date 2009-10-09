disable_pic  &&

#if [ $FFAMR != none ];then
#  OPTS="--enable-lib$FFAMR $FFMPEG_SWSCALE $OPTS"
#fi  &&

./configure  --prefix=${INSTALL_ROOT}/usr            \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             --enable-shared                         \
             --enable-pthreads                       \
             --disable-static                        \
             --disable-debug                         \
             --enable-postproc                       \
             --enable-gpl                            \
             $OPTS                         &&
make
