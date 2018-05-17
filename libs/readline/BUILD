[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"


./configure  --build=$BUILD                            \
             --prefix=${TRACK_ROOT}/usr              \
             --libdir=${TRACK_ROOT}/lib              \
             --infodir=${TRACK_ROOT}/usr/share/info  \
             --mandir=${TRACK_ROOT}/usr/share/man    \
             $OPTS                         &&
make DESTDIR=$INSTALL_ROOT                 &&

export LD_LIBRARY_PATH="${SOURCE_DIRECTORY}/shlib:${LD_LIBRARY_PATH}" &&

for i in readline history; do
  ln -sf lib${i}.so.${VERSION} shlib/lib${i}.so.${VERSION%.*}
done
