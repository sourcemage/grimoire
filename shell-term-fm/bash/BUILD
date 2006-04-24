[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"


./configure  --build=$BUILD                \
             --prefix=${TRACK_ROOT}/usr  \
             --bindir=${TRACK_ROOT}/bin  \
             --enable-static-link          \
             --with-bash-malloc=no 	   \
             $OPTS                         &&
make_single                                &&
make  bash DESTDIR=$INSTALL_ROOT           &&
mv    bash  bash.static                    &&
make  clean                                &&

./configure  --build=$BUILD                \
             --prefix=${TRACK_ROOT}/usr  \
             --bindir=${TRACK_ROOT}/bin  \
             --with-bash_malloc=no         \
             $OPTS                         &&
make DESTDIR=$INSTALL_ROOT
