SRC=$SOURCE_DIRECTORY/sources/$SPELL &&
OPTS+=" -DDISABLE_DOCSTRINGS=1" &&
if is_depends_enabled $SPELL python3; then
 OPTS+=" -DUSE_PYTHON_VERSION='3.5'"
fi &&
OPTS+=" -DBUILD_TESTS=false" &&
# install things to /usr
PATH="$QT5DIR/bin/:$PATH" &&
cd $SRC &&
cmake_build 
