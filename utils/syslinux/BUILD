# remove all flags
CFLAGS="" &&
# syslinux misuses LDFLAGS; these are supposed to be passed to CC when
# linking, not to LD. We try to workaround that here.
disable_relro &&
disable_z_now &&
LDFLAGS=${LDFLAGS//-Wl,} &&

default_build_make
