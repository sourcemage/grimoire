# Keep dependencies minimal: If for some reason glib2 is broken, it cannot
# subsequently be built when pkg-config is also broken due to linking to
# system glib2.
OPTS="$OPTS --with-internal-glib" &&
OPTS="$OPTS --with-pc-path=$TRACK_ROOT/usr/lib/pkgconfig:$TRACK_ROOT/usr/share/pkgconfig:$TRACK_ROOT/lib/pkgconfig" &&
default_build
