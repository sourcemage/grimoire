# XXX Build uses -Werror
CXXFLAGS="${CXXFLAGS/-Wunsafe-loop-optimizations}" &&
cd $SOURCE_DIRECTORY/src &&
CXX=${CXX} default_build_make       &&

if spell_installed perl; then
  cd $SOURCE_DIRECTORY/doc &&
  make upx.1
fi
