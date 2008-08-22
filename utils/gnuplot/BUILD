if [[ $GNUPLOT_SCM == "y" ]]; then
  ./prepare
fi &&
if [[ $GNUPLOT_LUA == "y" ]]; then
  LIBS="-llua $LIBS"
  cd $SOURCE_DIRECTORY/gnuplot_lua_terminal &&
  lua gnuplot.lua style                     &&
  cd $SOURCE_DIRECTORY
fi            &&
default_build
