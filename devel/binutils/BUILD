if [[ $BINUTILS_LTO == "y" ]];then
  OPTS+=" --enable-lto"
fi &&
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
make tooldir=/usr DESTDIR="$INSTALL_ROOT"
