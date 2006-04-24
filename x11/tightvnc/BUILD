patch  -p0  <  $SCRIPT_DIRECTORY/malloc-redefine.patch  &&
if ! use_gcc 3.3; then
  patch  -p0  <  $SCRIPT_DIRECTORY/gcc34.patch
fi           &&
xmkmf        &&
make_single  &&
make  World  &&
cd    Xvnc   &&
./configure  &&
make 
