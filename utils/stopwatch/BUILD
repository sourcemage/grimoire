make CFLAGS="${CFLAGS} `awk -F= '/^CFLAGS/ { print $2; }' Makefile`" &&

if list_find "${LDFLAGS}" "-s"; then
  strip -v "stopwatch"
fi
