OPTS="--prefix=$INSTALL_ROOT/usr \
      --sbindir=$INSTALL_ROOT/sbin \
      --libexecdir=$INSTALL_ROOT/lib/udev \
      --with-rootlibdir=$INSTALL_ROOT/lib \
      $UDEV_OPTS $UDEV_HWDB \
      $OPTS" &&

if [[ "${UDEV_HWDB}" = '--enable-hwdb' ]]; then
  if [[ "$(get_spell_provider ${SPELL} USBIDS)" == 'hwdata' ]]; then
    OPTS="$OPTS --with-usb-ids-path=/usr/share/hwdata/usb.ids"
  elif [[ "$(get_spell_provider ${SPELL} USBIDS)" == 'usbutils' ]]; then
    OPTS="$OPTS --with-usb-ids-path=/usr/share/usb.ids"
  else
    message "${PROBLEM_COLOR}unknown USBIDS provider, you are on your own.${DEFAULT_COLOR}"
  fi &&

  if [[ "$(get_spell_provider ${SPELL} PCIIDS)" == 'hwdata' ]]; then
    OPTS="$OPTS --with-pci-ids-path=/usr/share/hwdata/pci.ids"
  elif [[ "$(get_spell_provider ${SPELL} PCIIDS)" == 'pciutils' ]]; then
    OPTS="$OPTS --with-pci-ids-path=/usr/share/pci.ids"
  else
    message "${PROBLEM_COLOR}unknown PCIIDS provider, you are on your own.${DEFAULT_COLOR}"
  fi
fi &&

default_build
