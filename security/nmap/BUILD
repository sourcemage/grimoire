LDFLAGS="${LDFLAGS/-Wl,--as-needed/}" &&

OPTS="$NMAP_OPTS --with-libdnet=included $OPTS" &&
OPTS="--without-nmap-update $OPTS"

export PYTHON=python2 &&
default_build
