disable_pic  &&

#if [ $FFAMR != none ];then
#  OPTS="--enable-$FFAMR $OPTS"
#fi  &&

OPTS="$FFMPEG_SWSCALE $OPTS" &&

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
