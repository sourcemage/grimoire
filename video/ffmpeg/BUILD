disable_pic  &&

#if [ $FFAMR != none ];then
#  OPTS="--enable-$FFAMR $OPTS"
#fi  &&

OPTS="$FFMPEG_SWSCALE $OPTS" &&

# fixing issue #381
if is_depends_enabled $SPELL openjpeg; then
    CFLAGS="$CFLAGS -I${INSTALL_ROOT}/usr/include/openjpeg-1.5"
fi &&

LDFLAGS=${LDFLAGS//-Wl,--as-needed/}  &&

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
