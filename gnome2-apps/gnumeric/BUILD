if [[ $SSCONVERT == y ]]; then
  OPTS="$OPTS --enable-ssconvert"
else
  OPTS="$OPTS --disable-ssconvert"
fi &&

if [[ $SSINDEX == y ]]; then
  OPTS="$OPTS --enable-ssindex"
else
  OPTS="$OPTS --disable-ssindex"
fi &&

if [[ $SOLVER == y ]]; then
  OPTS="$OPTS --enable-solver"
else
  OPTS="$OPTS --disable-solver"
fi &&

if [[ $LONGDOUBLE == y ]]; then
  OPTS="$OPTS --with-long-double"
else
  OPTS="$OPTS --without-long-double"  
fi &&

if [[ $GNUMERIC_DEVEL != y ]]; then
  make_single
fi &&
default_build  &&
make_normal
