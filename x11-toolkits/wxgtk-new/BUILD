OPTS="$OPTS
  --enable-optimise
  --disable-debug
  --disable-monolithic
  --enable-shared
  --with-libiconv-prefix=$INSTALL_ROOT/usr
  --enable-geometry
  --enable-unicode
  --enable-graphics_ctx
" &&

case "$HOST" in
  (*-musl)
    OPTS+=' --disable-xlocale'
    ;;
esac &&

# wx project recommends building in a separate directory
cd $SOURCE_DIRECTORY   &&
mkdir -p bld-dir         &&
cd bld-dir &&
ln -s ../configure &&
default_build
