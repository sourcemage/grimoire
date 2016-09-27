if is_depends_enabled $SPELL qtbase; then
  export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig"
  export PATH+=":$QT5DIR/bin"
fi &&
OPTS+=" --enable-languages=${GPG_LANG/ /,}" &&
default_build

