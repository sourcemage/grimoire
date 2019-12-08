# coreutils provides kill
OPTS+=" --disable-kill" &&
# simpleinit-msb provides pidof
if spell_ok "simpleinit-msb"; then
  OPTS+=" --disable-pidof"
fi &&
default_build
