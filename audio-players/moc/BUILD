#breaks the compile
if ! gaze install ncurses | grep -q "libncursesw.so$"; then
  message "${MESSAGE_COLOR}Cannot find libncursesw.so, adding --without-ncursesw configure option.${DEFAULT_COLOR}" &&
  OPTS="--without-ncursesw $OPTS"
fi &&

if [ "$DDEBUG" == "y" ]; then
  OPTS="$OPTS  --disable-debug"
fi &&

default_build
