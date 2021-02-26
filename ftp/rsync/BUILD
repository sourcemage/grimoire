make_single &&

# LDFLAGS containing "-s" calls gcc and/or ld with "-s" which means --strip-all
# with current (2.36) binutils and perhaps earlier versions this causes
# relocation entries in the .rela.plt section of type R_X86_64_IRELATIV to be
# replaced with 0-entries having type R_X86_64_NONE (value 0). This breaks the
# STT_GNU_IFUNC mechanism used by certain shared libraries breaking the rsync
# binary. 
#
# Interestingly "strip -s" on the same binary which also is supposed to "strip
# all" does not show this behavior so it is somehow different from the behavior
# of ld. Perhaps it is a bug in binutils, though I was not able to find
# anything relevant.

LDFLAGS=${LDFLAGS//-s /-Wl,--strip-debug } &&
LDFLAGS=${LDFLAGS/%-s/-Wl,--strip-debug} &&
default_build &&
make_normal
