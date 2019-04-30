cd $SOURCE_DIRECTORY &&
mkdir -p builddir &&
cd builddir &&
# do aout-of-tree build
OPTS+=" --enable-gold --disable-tests --enable-strip --disable-jemalloc" &&
$SOURCE_DIRECTORY/js/src/configure --prefix=${INSTALL_ROOT}/usr $OPTS &&
make
