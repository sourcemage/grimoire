(

  message "${MESSAGE_COLOR}Checking for Apache 1.x${DEFAULT_COLOR}" &&
  httpd -v | grep -q "Apache/1\." &&

  patch -p1 < $SCRIPT_DIRECTORY/$SPELL.diff &&
  configure --with-target=Apache &&
  
  make 	           &&
  prepare_install  &&
  cp mod_csacek.so /usr/libexec/

) >$C_FIFO 2>&1
