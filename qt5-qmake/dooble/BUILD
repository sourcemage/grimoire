cd $SOURCE_DIRECTORY &&
if is_depends_enabled qt6base;then
  export PATH="$QT6DIR/bin:$PATH"
  export PKG_CONFIG_PATH="$QT6DIR/lib/pkgconfig" 
  export QT_MAJOR_VERSION=6
  qt6_build
else
  export QT_MAJOR_VERSION=5
  qt5_build  
fi
