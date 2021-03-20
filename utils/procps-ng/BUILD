# - disable building shared library
# - kill is provided by coreutils
# - enable SIGWINCH handling for top
OPTS+=' --disable-static --disable-kill --enable-sigwinch' &&
# simpleinit-msb provides pidof
if spell_ok "simpleinit-msb"; then
  OPTS+=" --disable-pidof"
fi &&
default_build
