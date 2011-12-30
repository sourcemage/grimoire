if [[ "$LIBFREENECT_AUDIO" == "y" ]]; then
  OPTS="-DBUILD_AUDIO=YES $OPTS"
fi &&

cmake_build &&

if [[ "$LIBFREENECT_PYTHON_WRAPPER" == "y" ]]; then
  message "${MESSAGE_COLOR}python wrapper${DEFAULT_COLOR}" &&
  cd $SOURCE_DIRECTORY/wrappers/python &&
  CFLAGS="-I/usr/lib/python2.7/site-packages/numpy/core/include/ -I$SOURCE_DIRECTORY/include/" default_build_python
fi
