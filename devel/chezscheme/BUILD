CFLAGS="${CFLAGS//-ffast-math}" &&
if is_depends_enabled "$SPELL" libiconv; then
  LDFLAGS+=' -liconv'
fi &&
./configure --installprefix="$INSTALL_ROOT"/usr $OPTS &&
make
