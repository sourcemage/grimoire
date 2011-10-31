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

if [[ $WICD_KDEVER == "4.x" ]]; then
  KDE4_PREFIX=`${INSTALL_ROOT}/usr/bin/kde4-config --prefix` &&
  OPTS="--kdedir=${KDE4_PREFIX}/share/applications/kde4/ $OPTS" &&
  OPTS="--autostart=${KDE4_PREFIX}/etc/xdg/autostart/ $OPTS"
else
  OPTS="--no-install-kde $OPTS"
fi &&

python setup.py configure $OPTS
