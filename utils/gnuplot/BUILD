if is_depends_enabled $SPELL qtbase; then
  export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig"
  export PATH+=":$QT5DIR/bin"
fi &&
# disable-raise-console needed because of
# https://sourceforge.net/p/gnuplot/mailman/message/34739833/
# Gtk2 and gtk3 removed a function that is still used in the wxt code.
OPTS="--without-tutorial --disable-raise-console $OPTS" &&
default_build
