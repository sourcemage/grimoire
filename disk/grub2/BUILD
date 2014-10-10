OPTS="${OPTS} ${GRUB2_OPTS} -disable-werror" &&
OPTS="$OPTS --with-platform=${GRUB2_PLATFORM%/*}" &&
CFLAGS=${CFLAGS//-m64/} &&
CFLAGS=${CFLAGS//-O(\d|fast)/-Os} &&
LDFLAGS=${LDFLAGS//-s /} &&
LDFLAGS=${LDFLAGS%-s} &&
disable_pic force &&
default_build
