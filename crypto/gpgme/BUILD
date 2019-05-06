GPG_LANG=no
if [ "$GPG_LANG_CXX" = y ]; then
  GPG_LANG=cpp
fi &&
if is_depends_enabled "$SPELL" qtbase; then
  export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig"
  export PATH+=":$QT5DIR/bin"
  GPG_LANG="$GPG_LANG,qt"
fi &&
if is_depends_enabled "$SPELL" python3 ||
   is_depends_enabled "$SPELL" python; then
  GPG_LANG="$GPG_LANG,python"
fi &&
OPTS+=" --enable-languages=${GPG_LANG#no,}" &&
default_build
