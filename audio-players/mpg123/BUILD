if [[ "$MPG123_WITH_AUDIO" != "" ]]; then
	OPTS="--with-audio=$MPG123_WITH_AUDIO $OPTS"
fi &&
if [[ "$MPG123_SEEKTABLE" != "" ]]; then
  OPTS="--with-seektable=$MPG123_SEEKTABLE $OPTS" 
fi &&
OPTS="$MPG123_MODULES $OPTS" &&
if [[ ${SMGL_COMPAT_ARCHS[0]} == 32 ]]; then
  # Installing both libmpg123 and libmpg123_64, as recommended by upstream (yes, that's me;-).
  message "${MESSAGE_COLOR}Preparing dual build for providing libmpg123 for small and large files.$DEFAULT_COLOR"
  OPTS="$OPTS --disable-modules --disable-largefile" default_build &&
  make DESTDIR="$SOURCE_DIRECTORY/mpg123-smallfile" install # Will grab the library build later from there.
fi &&
# Sane systems, in this case 64 bit Linux, just need default build.
# On 32 bit systems, default build will enable largefile support for libmpg123_64
default_build
