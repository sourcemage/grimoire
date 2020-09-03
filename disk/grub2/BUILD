OPTS="${OPTS} ${GRUB2_OPTS} -disable-werror" &&
OPTS="$OPTS --with-platform=${GRUB2_PLATFORM/*-}" &&
CFLAGS=${CFLAGS//-m64/} &&
CFLAGS=$(echo ${CFLAGS} | sed -r "s;-O([0-9]|fast);-Os;g") &&
LDFLAGS=${LDFLAGS//-s /} &&
LDFLAGS=${LDFLAGS%-s} &&
# Don't use gold linker (ld.gold), use old bfd
# Otherwise you might get this error:
# grub-install: error: `/usr/lib/grub/i386-pc/kernel.img' is miscompiled: its start address is 0x9074 instead of 0x9000: ld.gold bug?.
LDFLAGS=${LDFLAGS//-Wl,-fuse-ld=gold/} &&
LDFLAGS+=" -Wl,-fuse-ld=bfd" &&

disable_pic force &&
default_build
