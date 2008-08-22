. ${TRACK_ROOT}/usr/share/GNUstep/Makefiles/GNUstep.sh
local backend opts
for backend in $GNUSTEP_BACKEND ; do
opts="--enable-server=x11 --enable-graphics=$backend --with-name=$backend"
pushd $SOURCE_DIRECTORY.$backend
OPTS="$OPTS --build=${BUILD}";
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}";
./configure                                    \
     --prefix=${INSTALL_ROOT}/usr              \
     --sysconfdir=${INSTALL_ROOT}/etc          \
     --localstatedir=${INSTALL_ROOT}/var       \
     --mandir=${INSTALL_ROOT}/usr/share/man    \
     --infodir=${INSTALL_ROOT}/usr/share/info  \
     $opts                                     \
     $OPTS                                     &&
make
popd
done
