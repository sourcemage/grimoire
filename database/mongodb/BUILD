create_account mongodb &&

if ! list_find "$LDFLAGS" "-s"; then
  OPTS="--nostrip $OPTS"
fi &&

OPTS="--js-engine=$MONGODB_JSE --disable-warnings-as-errors $OPTS" &&

scons all --jobs=$MAKE_NJOBS --prefix="$INSTALL_ROOT/usr" $OPTS
