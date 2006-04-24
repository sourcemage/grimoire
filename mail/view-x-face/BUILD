(

  cp $SOURCE_CACHE/$SOURCE ./$SPELL				&&
  patch $SPELL < $SCRIPT_DIRECTORY/viewer-patch.diff		&&
  chmod 555 $SPELL						&&

  prepare_install                                             	&&
  cp $SPELL /usr/bin

) > $C_FIFO 2>&1
