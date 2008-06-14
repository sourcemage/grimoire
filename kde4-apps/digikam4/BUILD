#cd $SOURCE_DIRECTORY &&
# avoid gcc-4.3 bug
CFLAGS=${CFLAGS/-O3/-O0 -fno-tree-pre}
CXXFLAGS=${CXXFLAGS/-O3/-O0 -fno-tree-pre}
default_build
