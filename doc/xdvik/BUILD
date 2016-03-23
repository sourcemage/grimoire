mkdir -p smgl-build &&
cd smgl-build &&
ln -sf ../configure . &&
OPTS="$XDVIK_OPTS --with-xdvi-x-toolkit=$XDVIK_KIT --with-ps=$XDVIK_PS --disable-multiplatform  $OPTS" &&
OPTS+=" --disable-native-texlive-build" &&
default_build
