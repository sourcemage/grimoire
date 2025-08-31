if is_depends_enabled $SPELL qt6base; then
  export PKG_CONFIG_PATH=$QT6DIR/lib/pkgconfig &&
  PATH+=":$QT6DIR/bin"
fi  &&
if is_depends_enabled mesa libglvnd;then
  LDFLAGS+=' -lGL'
fi &&
OPTS+=" $V4L_BPF" &&

default_build

