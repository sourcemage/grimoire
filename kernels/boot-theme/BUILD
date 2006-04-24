(

  prepare_install                                                       &&
  mkdir -p /etc/bootsplash/themes                                       &&
  cp -rv $THEME /etc/bootsplash/themes/$THEME                           &&
  touch /boot/initrd.splash                                             &&

  for file in $(find /etc/bootsplash/themes/$THEME/config -type f); do
    splash -s -f $file >> /boot/initrd.splash
  done

) > $C_FIFO 2>&1

