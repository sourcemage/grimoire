invoke_gcc
patch -p0 < $SCRIPT_DIRECTORY/gcc-3.4.patch   &&
patch -p0 < $SCRIPT_DIRECTORY/Makefile.patch  &&

sedit "s/-msse/$CFLAGS/"  Makefile.ffmpeg     &&
if ! echo $CFLAGS | grep -q -- "-msse"; then
  echo "#undef HAVE_BUILTIN_VECTOR" >>    \
  ffmpeg-0.4.8/libavcodec/dsputil.h
fi  &&
if ! echo $CFLAGS | grep -q -- "-O."; then
  CFLAGS="$CFLAGS -O2"
fi  &&
sedit  "s:quicktime/ffmpeg:ffmpeg:"  configure  &&
./configure &&
make
