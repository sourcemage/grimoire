OPTS+=' -DSTEMMING=0'
if is_depends_enabled $SPELL qtbase;then
  PATH="$QT5DIR/bin/:$PATH"
  export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig"
fi &&
cmake_build

