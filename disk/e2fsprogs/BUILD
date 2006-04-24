  [[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"
patch -p0 <  $SPELL_DIRECTORY/inc.diff &&

./configure  --host=${BUILD}                           \
             --prefix=${TRACK_ROOT}/usr              \
             --infodir=${TRACK_ROOT}/usr/share/info  \
             --mandir=${TRACK_ROOT}/usr/share/man    \
             --with-root-prefix=${TRACK_ROOT}        \
             --enable-elf-shlibs                       \
             ${OPTS}                             &&
make DESTDIR=$INSTALL_ROOT
