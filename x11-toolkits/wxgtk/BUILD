OPTS="$OPTS
  --enable-optimise
  --disable-debug
  --disable-monolithic
  --enable-shared
  --with-libiconv-prefix=$INSTALL_ROOT/usr
  --enable-geometry
  --enable-unicode
  --with-gtk=2
" &&
if ! list_find WX_CONTRIB "xrc" || ! list_find WXGTK_OPTS "xrc"
then
  OPTS="--enable-xrc $OPTS"	
fi  &&
default_build &&
for COMPONENT in $WX_CONTRIB $WXGTK_OPTS; do
  if [ $COMPONENT=="xrc" ]; then continue; fi &&
  make -C contrib/src/$COMPONENT
done
