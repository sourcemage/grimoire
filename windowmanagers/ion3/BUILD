cd  "$SOURCE_DIRECTORY/build/ac"  &&
autoreconf                        &&

OPTS="$ION3_XINERAMA $ION3_LOCALE $OPTS --build=${BUILD}"  &&

if [[ $CROSS_INSTALL == on ]]
then
  OPTS="$OPTS --host=${HOST}"
fi  &&

./configure  --prefix=${INSTALL_ROOT}/usr              \
             --sysconfdir=${INSTALL_ROOT}/etc          \
             --localstatedir=${INSTALL_ROOT}/var       \
             --mandir=${INSTALL_ROOT}/usr/share/man    \
             --infodir=${INSTALL_ROOT}/usr/share/info  \
             $OPTS                                     &&

cd  "$SOURCE_DIRECTORY"  &&

make
