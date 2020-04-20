OPTS="--enable-shared $PYTHON_OPTS $OPTS" &&

# The following file from kdebindings has a syntax error that
# makes Python compilation fail
local PYTHON_VERSION=`echo $VERSION|cut -d. -f1,2`
if [[ -f $INSTALL_ROOT/usr/lib/python$PYTHON_VERSION/pydcop.py ]]; then
  mkdir "$SOURCE_DIRECTORY/spell-tmp" &&
  mv "$INSTALL_ROOT/usr/lib/python$PYTHON_VERSION/pydcop.py" \
    "$SOURCE_DIRECTORY/spell-tmp"
fi &&

default_build &&

# python -c 'print "(c)", "lynx"*3'
# can only have one primary python, the others must be alt
if [[ $PY2K == y ]]; then
  make install DESTDIR="$SOURCE_DIRECTORY/anywhere/$INSTALL_ROOT"
else
  make altinstall DESTDIR="$SOURCE_DIRECTORY/anywhere/$INSTALL_ROOT"
fi &&

message "${MESSAGE_COLOR}Fake stage complete, installing to real path...${DEFAULT_COLOR}"
