create_account mongodb &&

# use bundled spidermonkey, 2.2 will switch to V8
OPTS="--sharedclient --usesm $OPTS" &&

scons --jobs=$MAKE_NJOBS --prefix="$INSTALL_ROOT/usr" $OPTS
