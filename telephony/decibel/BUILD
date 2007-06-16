# don't build broken demos
#sed -i "/(demos)/D" CMakeLists.txt &&
if [ $DEC_SVN = y ]; then
  source $GRIMOIRE/kde4/FUNCTIONS  &&
  default_build
else
  qt4_build
fi
