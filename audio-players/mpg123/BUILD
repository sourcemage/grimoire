if [[ "$MPG123_WITH_AUDIO" != "" ]]; then
	OPTS="--with-audio=$MPG123_WITH_AUDIO $OPTS"
fi &&
if [[ "$MPG123_SEEKTABLE" != "" ]]; then
  OPTS="--with-seektable=$MPG123_SEEKTABLE $OPTS" 
fi &&
OPTS="$MPG123_MODULES $OPTS" &&
default_build
