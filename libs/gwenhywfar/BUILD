OPTS+="--with-guis=${GWEN_GUI}"
if list_find "$GWEN_GUI" qt5;then
  PATH="$QT5DIR/bin/:$PATH"
  export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig"
fi &&

default_build
