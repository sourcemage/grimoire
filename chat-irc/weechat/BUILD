if [ "$DEV_DEBUG" == "y" ]; then
  if [ "$DEV_DEBUG_FULL" == "y" ]; then
    OPTS="$OPTS  --with-debug=2"
  else
    OPTS="$OPTS  --with-debug=1"
  fi
fi &&

if [ "$DEV_CMAKE" == "y" ]; then
  cd $SOURCE_DIRECTORY &&
  mkdir build &&
  cd build &&
  cmake .. -DPREFIX=/usr &&
  make
else
  if [ "$WEECHAT_DEVEL_CVS" == "y" ]; then
    ./autogen.sh
  fi &&
  default_build
fi
