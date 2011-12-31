if [[ "$LIBFREENECT_AUDIO" == "y" ]]; then
  OPTS="-DBUILD_AUDIO=YES $OPTS"
fi &&

cd $SOURCE_DIRECTORY  &&
mkdir -p build        &&
cd build              &&
prepare_cmake_flags   &&

# do not download and extract audios.bin if already in $SOURCE_CACHE
if [ -f $SOURCE_CACHE/audios.bin ]; then
  message "${MESSAGE_COLOR}audios.bin restore: $SOURCE_CACHE/audios.bin -> audios.bin${DEFAULT_COLOR}" &&
  cp $SOURCE_CACHE/audios.bin audios.bin
fi &&

cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_ROOT/usr -DSYSCONFDIR=$INSTALL_ROOT/etc $OPTS ../  &&
make &&

# audios.bin backup
if [ -f audios.bin ] && ! [ -f $SOURCE_CACHE/audios.bin ]; then
  message "${MESSAGE_COLOR}audios.bin backup: audios.bin -> $SOURCE_CACHE/audios.bin${DEFAULT_COLOR}" &&
  cp audios.bin $SOURCE_CACHE/audios.bin
fi &&

if [[ "$LIBFREENECT_PYTHON_WRAPPER" == "y" ]]; then
  message "${MESSAGE_COLOR}python wrapper${DEFAULT_COLOR}" &&
  cd $SOURCE_DIRECTORY/wrappers/python &&
  CFLAGS="-I/usr/lib/python2.7/site-packages/numpy/core/include/ -I$SOURCE_DIRECTORY/include/" default_build_python
fi
