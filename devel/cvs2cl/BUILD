(

  prepare_install                      &&
  
  cp     -f $SOURCE  /usr/bin/         &&
  chmod  +x          /usr/bin/$SOURCE

) > $C_FIFO 2>&1 && (
  
  #
  # we'll delete the source from cache so that we can update it as needed
  #
  rm  -f  $SOURCE_CACHE/$SOURCE

)
