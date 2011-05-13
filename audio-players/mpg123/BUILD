if [[ "$MPG123_WITH_AUDIO" != "" ]]; then
	OPTS="--with-audio=$MPG123_WITH_AUDIO $OPTS"
fi &&
if [[ "$MPG123_SEEKTABLE" != "" ]]; then
  OPTS="--with-seektable=$MPG123_SEEKTABLE $OPTS" 
fi &&
# Use .so for modules so it is safe to rip out the .la files.
OPTS="$MPG123_MODULES --with-module-suffix=.so $OPTS" &&
default_build
