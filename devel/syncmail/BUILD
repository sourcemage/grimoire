(

  patch -p1 < $SCRIPT_DIRECTORY/mailhost.patch &&
  prepare_install &&
  cp -f syncmail /usr/bin/ &&
  chmod a+x      /usr/bin/syncmail

) > $C_FIFO 2>&1
