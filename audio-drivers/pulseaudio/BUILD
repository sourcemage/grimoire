OPTS="${PULSEAUDIO_OPTS} ${OPTS}" &&
LDFLAGS="${LDFLAGS/-Wl,--as-needed}" &&

if [[ "$PULSE_DB" == 'simple' ]]; then
  OPTS+=" database=simple"
fi &&

default_build
