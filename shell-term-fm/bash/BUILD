[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

patch -p1 < $SCRIPT_DIRECTORY/bash-3.0-avoid_WCONTINUED-1.patch &&
patch -p1 < $SCRIPT_DIRECTORY/bash-3.0-display_wrap-1.patch &&

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
