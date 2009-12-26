if [[ $PSOPI == y ]]; then
   OPTS="$OPTS --enable-opi"
fi &&

OPTS="--disable-utils --enable-xpdf-headers $OPTS" &&

if is_depends_enabled $SPELL qt4; then
  export PATH="$INSTALL_ROOT/usr/bin/qt4:$PATH"
fi &&

default_build
