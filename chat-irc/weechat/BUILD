if [[ $WEECHAT_DEBUG == y ]]; then
  if [[ $WEECHAT_DEBUG_FULL == y ]]; then
    OPTS="$OPTS  --with-debug=2"
  else
    OPTS="$OPTS  --with-debug=1"
  fi
fi &&

if [[ $WEECHAT_CMAKE == y ]]; then
  cmake_build
else
  if [[ $WEECHAT_BRANCH == scm ]]; then
    ./autogen.sh
  fi &&
  default_build
fi
