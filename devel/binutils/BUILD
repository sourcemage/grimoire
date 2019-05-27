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
              --enable-ld=default           \
              --enable-gold                 \
              $OPTS  &&
make tooldir=/usr DESTDIR="$INSTALL_ROOT"
