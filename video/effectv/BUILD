# Set proper prefix
sedit  "s:^\(prefix =\).*:\1 ${INSTALL_ROOT}/usr:"  config.mk
sedit  "s:/man:/share/man:" config.mk
# Set proper CFLAGS
sedit  "s/^\(CFLAGS\.opt =\).*/\1 $CFLAGS/"  config.mk
# Makefile sets a special flag if the arch is i686.
[  "$( uname -m )" != "i686"  ]  &&  sedit  "s/^ARCH /#\0/"  config.mk
# Disable mmx support if cpu can't handle it.
grep  -q  mmx  /proc/cpuinfo  ||  sedit  "s/^USE_MMX/#\0/"  config.mk
# Disable nasm support if it isn't installed
sedit  "s/^USE_NASM.*$/$OPTS/"  config.mk
# There's no vloopback spell yet.
sedit  "s/^USE_VLOOPBACK/#\0/"  config.mk
make
