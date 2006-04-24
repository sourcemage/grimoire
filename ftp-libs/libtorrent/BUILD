# fix configure so our CXXFLAGS get used
sedit  's/test $CXXFLAGS/test -n "$CXXFLAGS"/'  configure  &&
# remove -O3 from CXXFLAGS on gcc 4.0.x, leads to wrong code -> segfault
if  use_gcc ^4; then
  CXXFLAGS="${CXXFLAGS/-O3/-Os}"
fi  &&
default_build
