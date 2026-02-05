# - disable building static library
# - enable SIGWINCH handling for top
OPTS="--disable-static --enable-sigwinch ${OPTS}" &&
# simpleinit-msb provides pidof
if spell_ok "simpleinit-msb"; then
  OPTS+=" --disable-pidof"
fi &&

OPTS+=" --bindir=$INSTALL_ROOT/bin --sbindir=$INSTALL_ROOT/sbin" &&
if is_depends_enabled $SPELL systemd; then
  LDFLAGS="$LDFLAGS -lsystemd" default_build
else
  default_build
fi
