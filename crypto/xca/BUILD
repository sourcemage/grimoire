CXXFLAGS+=" -fpermissive" &&
if is_depends_enabled $SPELL qtbase;then
  OPTS+=" --with-qt=$QT5DIR"
else
  OPTS+=" --with-qt=$QT4DIR"
fi &&
default_build
