if ! gcc --version  |  head -n 1  |  grep  '2\.95\.'; then
  patch -p0 < $SCRIPT_DIRECTORY/$SPELL-$VERSION-gcc3.patch
  patch -p0 < $SCRIPT_DIRECTORY/lemon2.patch
fi

default_build
