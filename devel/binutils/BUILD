# Temporary fix to solve texinfo errors
sed -i -e '325 s/@colophon/@&/' bfd/doc/bfd.texinfo &&
sed -i -e '336 s/@cygnus/@&/' bfd/doc/bfd.texinfo  &&
sed -i -e '7866 s/@colophon/@&/' ld/ld.texinfo &&
sed -i -e '7877 s/@cygnus/@&/' ld/ld.texinfo &&

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
              $OPTS  &&
make DESTDIR=$INSTALL_ROOT
