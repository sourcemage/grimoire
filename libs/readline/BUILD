[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"


./configure  --build=$BUILD                            \
             --prefix=${TRACK_ROOT}/usr              \
             --libdir=${TRACK_ROOT}/lib              \
             --infodir=${TRACK_ROOT}/usr/share/info  \
             --mandir=${TRACK_ROOT}/usr/share/man    \
        --with-shared-termcap-library ${OPTS} &&
make DESTDIR=$INSTALL_ROOT
