cd $SOURCE_DIRECTORY &&
OPTS="--lib=${INSTALL_ROOT}/usr/lib/${SPELL}/ \
      --share=${INSTALL_ROOT}/usr/share/${SPELL}/ \
      --etc=${INSTALL_ROOT}/etc/${SPELL}/ \
      --images=${INSTALL_ROOT}/usr/share/pixmaps/${SPELL}/ \
      --bin=${INSTALL_ROOT}/usr/bin/ \
      --sbin=${INSTALL_ROOT}/usr/sbin/ \
      --networks=${INSTALL_ROOT}/var/lib/${SPELL}/configurations/ \
      --log=${INSTALL_ROOT}/var/log/${SPELL}/ \
      --dbus=${INSTALL_ROOT}/etc/dbus-1/system.d/ \
      --desktop=${INSTALL_ROOT}/usr/share/applications/ \
      --icons=${INSTALL_ROOT}/usr/share/icons/hicolor/ \
      --translations=${INSTALL_ROOT}/usr/share/locale/ \
      --python=${INSTALL_ROOT}/usr/bin/python
      --pidfile=${INSTALL_ROOT}/var/run/${SPELL}/${SPELL}.pid \
      --no-install-init \
      $OPTS" &&

if [[ $WICD_KDEVER == "3.x" ]]; then
  OPTS="--kdedir=`${INSTALL_ROOT}/usr/bin/kde-config --prefix` $OPTS"
elif [[ $WICD_KDEVER == "4.x" ]]; then
  OPTS="--kdedir=`${INSTALL_ROOT}/opt/kde4/bin/kde4-config --prefix` $OPTS"
else
  OPTS="--no-install-kde $OPTS"
fi &&

echo $OPTS
python setup.py configure $OPTS
