if is_depends_enabled "$SPELL" python3; then
  # Fix build failure with Python 3.9.5, and possibly other versions
  pyinc=("$INSTALL_ROOT"/usr/include/python3.*/Python.h)
  CFLAGS+=" -I${pyinc%/Python.h}"
fi &&
# --datadir=... defines dictionary directory for cracklib;
# dictionary files ARE platform-dependent so it must not be /usr/shared
OPTS="$OPTS --datadir=$INSTALL_ROOT/usr/lib" &&
default_build &&
# no ldconfig for musl
case "$HOST" in
  (*-musl)
    sed -i -e '/^finish_cmds=/{s/=.*/=/}' libtool
    ;;
esac
