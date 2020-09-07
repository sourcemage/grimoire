if [[ "$MPG123_WITH_AUDIO" != "" ]]; then
	OPTS="--with-audio=$MPG123_WITH_AUDIO $OPTS"
fi &&
if [[ "$MPG123_SEEKTABLE" != "" ]]; then
  OPTS="--with-seektable=$MPG123_SEEKTABLE $OPTS" 
fi &&
OPTS="$MPG123_QUALITY $MPG123_MODULES $OPTS" &&
default_build_configure &&
find . -name Makefile \
| xargs sed -i 's,^\(LIBTOOL[[:space:]]*=[[:space:]]*\),\1'"$GRIMOIRE"'/libtool-nola ,' &&
default_build_make
