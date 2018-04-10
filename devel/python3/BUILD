OPTS="--enable-shared  $PYTHON3_OPTS $OPTS" &&
OPTS="--with-ensurepip=no $OPTS"            &&

EXTRA_CFLAGS="$CFLAGS" default_build &&

if [[ $PY3K == y ]]; then
  # python3 -c 'print ("(c)", "lynx"*3)'
  make install DESTDIR="$SOURCE_DIRECTORY/anywhere/$INSTALL_ROOT"
else
  make altinstall DESTDIR="$SOURCE_DIRECTORY/anywhere/$INSTALL_ROOT"
fi &&

message "Fake stage complete, installing to real path.."
