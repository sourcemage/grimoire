# don't build broken demos
#sed -i "/(demos)/D" CMakeLists.txt &&
#if [ $DEC_SVN = y ]; then
if is_depends_enabled $SPELL kdelibs4; then
  source $GRIMOIRE/kde4/FUNCTIONS  &&
  default_build
else
  qt4_build
fi
