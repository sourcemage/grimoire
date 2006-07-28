sedit 's/prefix=\/usr\/local/prefix=\/usr/;s|/man|/share/man|' inst.defs &&
sedit '/\#include \"l64seek.h\"/a\\#include \<errno.h\>' src/l64seek.c   &&
sedit '/#if defined(__linux__)/a\\#include \<errno.h\>/' src/disku.c     &&
make
