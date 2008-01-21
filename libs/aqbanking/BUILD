# local BACKENDS="aqhbci aqdtaus"  && aqdtaus is broken
local BACKENDS="aqhbci"  &&
local FRONTENDS="cbanking"                    &&

if  list_find  "$OPTS"  "--enable-libofx";  then
  BACKENDS="$BACKENDS aqofxconnect"
fi  &&

if [ "${AQBANKING_GTK}" == "y" ]; then
   local FRONTENDS="${FRONTENDS} g2banking"
fi  &&

if [ "${AQBANKING_QT}" == "y" ]; then
   FRONTENDS="${FRONTENDS} qbanking"          &&
   if spell_ok libchipcard2; then
      BACKENDS="${BACKENDS} aqgeldkarte"
   fi
else
   OPTS="${OPTS} --disable-qt3"
fi                                            &&

if [ "${AQBANKING_KDE}" == "y" ]; then
   FRONTENDS="${FRONTENDS} kbanking"
else
   OPTS="${OPTS} --disable-kde3"
fi                                            &&

if [ "${AQBANKING_QTTHREADS}" == "y" ]; then
   OPTS="${OPTS} --enable-qt3-treads"
fi                                            &&

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
make_single  &&
make  &&
make_normal
