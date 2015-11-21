OPTS="--enable-shared ${OPTS}"       &&
OPTS="$GRAPHICSMAGICK_16BIT ${OPTS}" &&

if [[ $GM_SNAP != y ]]
then
  OPTS="--without-png ${OPTS}"
fi  &&

default_build &&
make perl-build
