patch -p0 < $SCRIPT_DIRECTORY/raidtools-gcc-3.3.X.patch 	&&
# don't need INSTALL_ROOT, it's the build system's headers that matter
if grep -q 'getpageshift()' "/usr/include/asm/page.h"; then
  sedit '27 d' raidlib.c
fi && # this if for libc headers > 2.6.11.2 (2.6.12.0 e.g.)
default_build
