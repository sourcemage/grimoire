# - disable building shared library
# - kill is provided by coreutils
# - enable SIGWINCH handling for top
OPTS+=' --disable-static --disable-kill --enable-sigwinch' &&
# simpleinit-msb provides pidof
if spell_ok "simpleinit-msb"; then
  OPTS+=" --disable-pidof"
fi &&

if is_depends_enabled $SPELL systemd; then
  LDFLAGS="$LDFLAGS -lsystemd" default_build
else
  default_build
fi
