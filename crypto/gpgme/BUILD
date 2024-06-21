CFLAGS+=' -D_LARGEFILE64_SOURCE' &&
OPTS+=" --disable-gpg-test" &&
export QT6DIR=$INSTALL_ROOT/opt/qt6 &&
GPG_LANG=no
if [ "$GPG_LANG_CXX" = y ]; then
  GPG_LANG=cpp
fi &&
if is_depends_enabled "$SPELL" qt6base; then
  export PKG_CONFIG_PATH="$QT6DIR/lib/pkgconfig"
  export PATH+=":$QT6DIR/bin"
  GPG_LANG="$GPG_LANG,qt6"
fi &&
if is_depends_enabled "$SPELL" qtbase; then
  GPG_LANG="$GPG_LANG,qt5"
fi &&
if is_depends_enabled "$SPELL" python3 ||
   is_depends_enabled "$SPELL" python; then
  GPG_LANG="$GPG_LANG,python"
fi &&
OPTS+=" --enable-languages=${GPG_LANG#no,}" &&
default_build
