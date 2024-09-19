SRC=$SOURCE_DIRECTORY/sources/$SPELL &&
OPTS+=" -DDISABLE_DOCSTRINGS=1" &&
OPTS+=' -DSHIBOKEN_BUILD_TOOLS=true' &&
OPTS+=' -DSHIBOKEN_BUILD_LIBS=true'  &&
OPTS+=' -DCMAKE_UNITY_BUILD=true'    &&
OPTS+=' -DBUILD_TESTS=false' &&
# install things to /usr
PATH="$QT6DIR/bin/:$PATH" &&
cd $SRC &&
cmake_build 
