unset LIBBSD_CFLAGS LIBBSD_LIBS &&
if is_depends_enabled "$SPELL" libbsd; then
  LIBBSD_CFLAGS=$(pkg-config --cflags libbsd-overlay) &&
  LIBBSD_LIBS=$(pkg-config --libs libbsd-overlay)
fi &&
make \
  CC="${CC:-cc}" \
  HOSTCC="${HOSTCC:-${CC:-cc}}" \
  LIBBSD_CFLAGS="$LIBBSD_CFLAGS" \
  LIBBSD_LIBS="$LIBBSD_LIBS"
