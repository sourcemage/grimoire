[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

OPTS+=" $BASH_OPTS" &&

./configure  --build=$BUILD                \
             --prefix=${TRACK_ROOT}/usr  \
             --bindir=${TRACK_ROOT}/bin  \
             --sysconfdir=${TRACK_ROOT}/etc \
             --localstatedir=${TRACK_ROOT}/var \
             --mandir=${TRACK_ROOT}/usr/share/man \
             --infodir=${TRACK_ROOT}/usr/share/info \
             --enable-static-link          \
             --with-bash-malloc=no 	   \
             $OPTS                         &&
make  bash DESTDIR=$INSTALL_ROOT           &&
mv    bash  bash.static                    &&
make  clean                                &&

./configure  --build=$BUILD                \
             --prefix=${TRACK_ROOT}/usr  \
             --bindir=${TRACK_ROOT}/bin  \
             --sysconfdir=${TRACK_ROOT}/etc \
             --localstatedir=${TRACK_ROOT}/var \
             --mandir=${TRACK_ROOT}/usr/share/man \
             --infodir=${TRACK_ROOT}/usr/share/info \
             --with-bash_malloc=no         \
             $OPTS                         &&
make DESTDIR=$INSTALL_ROOT
