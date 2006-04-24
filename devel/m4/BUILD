OPTS="$OPTS --build=${BUILD}"
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

sedit  's:$(prefix)/info:$(prefix)/share/info:'  Makefile.in  &&

./configure  --build=$BUILD                \
             --prefix=${TRACK_ROOT}/usr  \
             $OPTS                         &&
make DESTDIR=$INSTALL_ROOT

