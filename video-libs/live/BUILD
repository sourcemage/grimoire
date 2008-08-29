sedit  's/strstream.h/strstream/'  groupsock/Groupsock.cpp     &&
sedit  's/strstream.h/strstream/'  groupsock/NetInterface.cpp  &&

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
