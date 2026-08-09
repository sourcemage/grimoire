if  is_depends_enabled $SPELL qt6base;then
  PATH+=":$QT6DIR/bin" &&
  LDFLAGS+=" -Wl,-rpath=$QT6DIR/lib" &&
  OPTS+=" --with-qmake6"
fi &&
default_build
