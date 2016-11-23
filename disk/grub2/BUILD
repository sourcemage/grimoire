OPTS="${OPTS} ${GRUB2_OPTS} -disable-werror" &&
OPTS="$OPTS --with-platform=${GRUB2_PLATFORM/*-} --target=${GRUB2_PLATFORM%-*}" &&
CFLAGS=${CFLAGS//-m64/} &&
CFLAGS=$(echo ${CFLAGS} | sed -r "s;-O([0-9]|fast);-Os;g") &&
LDFLAGS=${LDFLAGS//-s /} &&
LDFLAGS=${LDFLAGS%-s} &&
disable_pic force &&
default_build
