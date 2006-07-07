if [ "$ROOT_FILTER" == "y" ]; then
  OPTS="$OPTS --enable-root-filter"
fi  &&
if [ "$ENV_CHECK" == "n" ]; then
  OPTS="$OPTS --disable-env-check"
fi  &&

make_single    &&
default_build  &&
make_normal
