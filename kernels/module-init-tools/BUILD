[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"
make_single                           &&

if [ $OLD_TOO == y ] ; then
  cd $SOURCE_DIRECTORY2                                &&
  ./configure  --build=$BUILD                          \
               --prefix=${TRACK_ROOT}/               \
               --mandir=${TRACK_ROOT}/usr/share/man  \
                        $OPTS                          &&
  make   DESTDIR=$INSTALL_ROOT                         &&
  cd $SOURCE_DIRECTORY
fi  &&

#  default_build
./configure  --build=$BUILD                          \
             --prefix=${TRACK_ROOT}/               \
             --mandir=${TRACK_ROOT}/usr/share/man  \
             $OPTS                                   &&
make   DESTDIR=$INSTALL_ROOT MANS=
