OPTS="--enable-shared ${OPTS}"       &&
OPTS="$GRAPHICSMAGICK_16BIT ${OPTS}" &&
OPTS+=' --disable-static' &&
default_build &&
if is_depends_enabled $SPELL perl;then
  make perl-build
fi
