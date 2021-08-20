OPTS="$OPTS --build=${BUILD}"
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}" 

if [[ $UTF8 == y ]]; then
  OPTS="$OPTS  --enable-widec"
fi  &&
OPTS+=" --with-shared --enable-pc-files" &&
./configure       --prefix="$TRACK_ROOT"/usr \
              --sysconfdir="$TRACK_ROOT"/etc \
           --localstatedir="$TRACK_ROOT"/var \
                  --libdir="$TRACK_ROOT"/lib \
  --with-pkg-config-libdir="$TRACK_ROOT"/usr/lib/pkgconfig \
                  --mandir="$TRACK_ROOT"/usr/share/man \
                 --infodir="$TRACK_ROOT"/usr/share/info \
                           $OPTS &&
make DESTDIR="$INSTALL_ROOT"
