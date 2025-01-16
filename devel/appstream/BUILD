OPTS+=' stemming=false' &&
if is_depends_enabled $SPELL qt6base; then
  PATH="$QT6DIR/bin:$PATH" &&
  export PKG_CONFIG_PATH="$QT6DIR/lib/pkgconfig"
fi &&
default_build
