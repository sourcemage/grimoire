OPTS="$OPTS
  --enable-optimise
  --disable-debug
  --disable-monolithic
  --enable-shared
  --with-opengl
  --with-libiconv-prefix=$INSTALL_ROOT/usr
  --enable-geometry
  --enable-xrc
  --enable-unicode
  --with-gtk=2
" &&
default_build &&
for COMPONENT in $WX_CONTRIB; do
  make -C contrib/src/$COMPONENT
done
