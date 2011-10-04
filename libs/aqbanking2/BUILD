local BACKENDS="aqhbci aqdtaus"  &&
local FRONTENDS="cbanking"                    &&

if  list_find  "$OPTS"  "--enable-libofx";  then
  BACKENDS="$BACKENDS aqofxconnect"
fi  &&

if [ "${AQBANKING_GTK}" == "y" ]; then
   local FRONTENDS="${FRONTENDS} g2banking"
fi  &&

OPTS="${OPTS} --disable-qt3"
OPTS="${OPTS} --disable-kde3"

./configure --build=${BUILD}                           \
            --host=${HOST}                             \
            --prefix=${INSTALL_ROOT}/usr               \
            --sysconfdir=${INSTALL_ROOT}/etc           \
            --localstatedir=${INSTALL_ROOT}/var        \
            --mandir=${INSTALL_ROOT}/usr/share/man     \
            --infodir=${INSTALL_ROOT}/usr/share/info   \
            --with-backends="${BACKENDS}"              \
            --with-frontends="${FRONTENDS}"            \
            $OPTS                                      &&

make
