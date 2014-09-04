sedit  's/strstream.h/strstream/'  groupsock/Groupsock.cpp     &&
sedit  's/strstream.h/strstream/'  groupsock/NetInterface.cpp  &&

# workaround for mplayer 1.0rc4 build problem, see https://bugs.archlinux.org/task/28759
CFLAGS="-DRTSPCLIENT_SYNCHRONOUS_INTERFACE=1 $CFLAGS"          &&
sedit 's/#define _RTSP_CLIENT_HH/#define _RTSP_CLIENT_HH\n\n#define RTSPCLIENT_SYNCHRONOUS_INTERFACE 1/' liveMedia/include/RTSPClient.hh  &&

case "${SMGL_COMPAT_ARCHS[1]}" in
     x86_64)
        sedit  's/ -O./ '"$CFLAGS"' -fPIC -DPIC -Wno-deprecated /'  config.linux
        ;;
     *)
        sedit  's/ -O./ '"$CFLAGS"' -Wno-deprecated /'  config.linux
        ;;
esac

./genMakefiles  linux  &&
make
