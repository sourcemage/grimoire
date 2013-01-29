# remove all flags
CFLAGS="" &&
#
# SysLinux is very picky about LDFLAGS...
#
LDFLAGS=${LDFLAGS/-Wl,-O1}   &&
LDFLAGS=${LDFLAGS/-Wl,--hash-style=gnu}   &&
LDFLAGS=${LDFLAGS/-Wl,--as-needed}   &&

make
