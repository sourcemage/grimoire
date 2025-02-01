. "$GRIMOIRE"/FUNCTIONS
if is_depends_enabled $SPELL qt6base; then
  export PKG_CONFIG_PATH="$QT6DIR/lib/pkgconfig${PKG_CONFIG_PATH:+:$PKG_CONFIG_PATH}" \
         PATH+=":$QT6DIR/bin"
fi &&
default_build_configure &&
rake
