CFLAGS="${CFLAGS/-ffast-math/}"
# Use the mdbtools 1.x API; detection is broken with GCC 14+
CFLAFS+=" -DMDB_BIND_COLUMN_FOUR_ARGS" &&
force_dialect gnu99 &&
default_build
