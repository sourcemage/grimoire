disable_pic  &&

#
# Cannot find -lxvid with -Wl,--as-needed in LDFLAGS
#
LDFLAGS=${LDFLAGS/-Wl,--as-needed} &&

#if [ $FFAMR != none ];then
#  OPTS="--enable-lib$FFAMR $FFMPEG_SWSCALE $OPTS"
#fi  &&

check_tmp_noexec /tmp &&
./configure  --prefix=${INSTALL_ROOT}/usr            \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             --enable-shared                         \
             --enable-pthreads                       \
             --disable-static                        \
             --disable-debug                         \
             --enable-gpl                            \
             $OPTS                         &&
check_tmp_noexec /tmp &&
make
