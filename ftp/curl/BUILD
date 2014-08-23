if [[ "$CFLAGS" != "${CFLAGS//-DPIC/}" ]]; then
  CFLAGS="${CFLAGS//-DPIC/}" &&
  CPPFLAGS="$CPPFLAGS -DPIC "
fi  &&

default_build
