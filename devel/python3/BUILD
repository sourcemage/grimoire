OPT="$CFLAGS" &&

OPTS="--enable-shared $PYTHON3_OPTS $OPTS" &&

# The following file from kdebindings has a syntax error that
# makes Python compilation fail
local PYTHON_VERSION=`echo $VERSION|cut -d. -f1,2`
if [[ -f $INSTALL_ROOT/usr/lib/python$PYTHON_VERSION/pydcop.py ]]; then
  mkdir "$SOURCE_DIRECTORY/spell-tmp" &&
  mv "$INSTALL_ROOT/usr/lib/python$PYTHON_VERSION/pydcop.py" \
    "$SOURCE_DIRECTORY/spell-tmp"
fi &&

default_build &&

if [[ $PY3K == y ]]; then
  # python3 -c 'print ("(c)", "lynx"*3)'
  make fullinstall DESTDIR="$SOURCE_DIRECTORY/anywhere/$INSTALL_ROOT"
else
  make install DESTDIR="$SOURCE_DIRECTORY/anywhere/$INSTALL_ROOT"
fi &&

message "Fake stage complete, installing to real path.."
