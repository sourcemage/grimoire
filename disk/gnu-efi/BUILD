# Filtering LDFLAGS
TMPLDFLAGS="${LDFLAGS}" &&
LDFLAGS="${LDFLAGS//-Wl,/}" &&
LDFLAGS="${LDFLAGS//,/ }" &&

default_build_make &&

# Restoring
LDFLAGS="${TMPLDFLAGS}"
