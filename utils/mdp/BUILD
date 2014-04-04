OPTS="--prefix=$INSTALL_ROOT/usr" &&

if [[ $MDP_DEBUG == y ]]; then
  OPTS="--debug $OPTS"
fi &&

./configure "$OPTS" &&

make_single &&
make &&
make_normal
