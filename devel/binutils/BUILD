export CFLAGS+=" -Wno-format-overflow" &&
OPTS+=' --disable-gprofng' &&

if [[ $BINUTILS_LTO == "y" ]];then
  OPTS+=" --enable-lto"
fi &&

disable_fortify_source &&

mkdir  buildit &&
cd     buildit &&

../configure  --host=$HOST                  \
              --build=$BUILD                \
              --prefix=/usr                 \
              --infodir=${TRACK_ROOT}/usr/share/info     \
              --mandir=${TRACK_ROOT}/usr/share/man       \
              --enable-shared               \
              --disable-static              \
              --disable-werror              \
              --enable-ld=yes               \
              --enable-gold=yes             \
              $OPTS  &&
make tooldir=/usr DESTDIR="$INSTALL_ROOT" &&
disable_fortify_source &&

# Install into a staging area before messing with the installed
# binutils. The install phase should not try to do anything
# funky, like relinking something. Do not mess with binutils.
make_single &&
make tooldir=/usr DESTDIR="$PWD/INSTALL_ROOT" install &&
if [[ "${BINUTILS_LIBIBERTY}" == "y" ]]; then
  install ../include/libiberty.h "INSTALL_ROOT/usr/include/." &&
  install ./libiberty/libiberty.a "INSTALL_ROOT/usr/lib/"
fi &&
make_normal &&
# set default linker
ln -sf ld.$BINUTILS_LINKER INSTALL_ROOT/usr/bin/ld
