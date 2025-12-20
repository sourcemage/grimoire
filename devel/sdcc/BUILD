# Setting DEFAULT_ASSEMBLER is necessary due to a bug in the support/cpp/gcc
# configure script. [SDCC 4.5.0]
# See: https://sourceforge.net/p/sdcc/bugs/3896/
export DEFAULT_ASSEMBLER="$(which as)" &&
force_dialect gnu11 &&
CFLAGS+=" -Wno-unused" &&
default_build
