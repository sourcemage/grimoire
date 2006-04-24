[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"
patch -p1 < $SCRIPT_DIRECTORY/readline-5.0-display_wrap-1.patch &&


./configure  --build=$BUILD                            \
             --prefix=${TRACK_ROOT}/usr              \
             --libdir=${TRACK_ROOT}/lib              \
             --infodir=${TRACK_ROOT}/usr/share/info  \
             --mandir=${TRACK_ROOT}/usr/share/man    \
             $OPTS                         &&
make DESTDIR=$INSTALL_ROOT
