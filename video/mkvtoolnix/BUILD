. "$GRIMOIRE"/FUNCTIONS
# This seems wrong. Don't we have a standard thing for qtbase-dependent stuff?
if is_depends_enabled $SPELL qt6base; then
  export PKG_CONFIG_PATH="$QT6DIR/lib/pkgconfig${PKG_CONFIG_PATH:+:$PKG_CONFIG_PATH}"
elif is_depends_enabled $SPELL qtbase; then
  export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig${PKG_CONFIG_PATH:+:$PKG_CONFIG_PATH}"
fi &&
default_build_configure &&
rake
