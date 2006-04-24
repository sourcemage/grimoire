(

  if httpd -v | grep -q "Apache/2\."; then
    message "${MESSAGE_COLOR}Compiling for Apache 2${DEFAULT_COLOR}" &&
    patch -p1 < $SCRIPT_DIRECTORY/$SPELL.diff &&
    mv Makefile.AP2 Makefile &&
    cp $SOURCE_CACHE/$SOURCE2 . &&
    make &&
    INSTALL_CMD='make install'
  else
    message "${MESSAGE_COLOR}Compiling for Apache 1.3${DEFAULT_COLOR}" &&
    apxs -o mod_fastcgi.so -c *.c &&
    INSTALL_CMD='apxs -a -i -n fastcgi mod_fastcgi.so'
  fi &&
  prepare_install &&
  $INSTALL_CMD

) > $C_FIFO 2>&1
