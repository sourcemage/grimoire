if ! gcc --version  |  head -n 1  |  grep  '2\.95\.'; then
  patch -p0 < $SCRIPT_DIRECTORY/$SPELL-$VERSION-gcc3.patch
fi

OPTS="$OPTS --disable-gtkmmtest"

default_build
