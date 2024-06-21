#if is_depends_enabled $SPELL qt6base; then
#  export PKG_CONFIG_PATH=$QT6DIR/lib/pkgconfig &&
#  PATH+=":$QT6DIR/bin"
#fi  &&
if is_depends_enabled $SPELL qtbase; then
  export PKG_CONFIG_PATH=$QT5DIR/lib/pkgconfig &&
  PATH+=":$QT5DIR/bin"
fi  &&

OPTS+=" $V4L_BPF" &&

default_build

