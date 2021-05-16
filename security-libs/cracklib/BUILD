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
