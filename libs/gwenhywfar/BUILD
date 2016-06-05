OPTS+="--with-guis=${GWEN_GUI}"
if list_find "$GWEN_GUI" qt5;then
  PATH="$QT5DIR/bin/:$PATH"
  export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig"
fi &&
if list_find "$GWEN_GUI" qt4;then
  PATH="$QT4DIR/bin/:$PATH"
  export PKG_CONFIG_PATH="$QT4DIR/lib/pkgconfig"
fi &&

default_build
