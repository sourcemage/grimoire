create_account mongodb &&

if ! list_find "$LDFLAGS" "-s"; then
  OPTS="--nostrip $OPTS"
fi &&

case $MONGODB_JSE in
  v8)
    OPTS="--usev8 $OPTS"
  ;;
  spidermonkey)
    OPTS="--usesm $OPTS"
  ;;
esac &&

OPTS="--mongod-concurrency-level=$MONGODB_CCL $MONGODB_OPTS $OPTS" &&

scons all --jobs=$MAKE_NJOBS --prefix="$INSTALL_ROOT/usr" $OPTS
