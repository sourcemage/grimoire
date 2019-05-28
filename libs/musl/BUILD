CFLAGS="${CFLAGS//-ffast-math}"
case "$HOST" in
*-musl)
  touch .native &&
  pfx="$INSTALL_ROOT/usr"
  ;;
*)
  pfx="$INSTALL_ROOT/opt/musl"
  ;;
esac
./configure --prefix="$pfx" --syslibdir="$INSTALL_ROOT/lib" $OPTS &&
make
