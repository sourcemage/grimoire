SRC=$SOURCE_DIRECTORY/sources/$SPELL &&
cd $SRC &&
OPTS+=" -DDISABLE_DOCSTRINGS=1" &&
OPTS+=' -DBUILD_TESTS=0' &&
OPTS+=' -DCMAKE_UNITY_BUILD=true' &&

# install things to /usr
PATH="$QT6DIR/bin/:$PATH" &&
cmake_build

