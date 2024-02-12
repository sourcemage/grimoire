if is_depends_enabled $SPELL qt6base; then
  export PKG_CONFIG_PATH="$QT6DIR/lib/pkgconfig"
  export PATH+=":$QT6DIR/bin"
fi &&
# disable-raise-console needed because of
# https://sourceforge.net/p/gnuplot/mailman/message/34739833/
# Gtk2 and gtk3 removed a function that is still used in the wxt code.
OPTS=" --disable-raise-console $OPTS" &&
default_build
