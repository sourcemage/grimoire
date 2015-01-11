OPTS="--disable-collab-backend-service --disable-collab-backend-tcp $ABIWORD_OPTS $OPTS" &&
if is_depends_enabled $SPELL gnome-vfs2; then
  CXXFLAGS="$CXXFLAGS -I/usr/include/gnome-vfs-2.0"
  LDFLAGS="$LDFLAGS -lgnomevfs-2"
fi &&
default_build
