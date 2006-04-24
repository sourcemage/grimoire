(

  sedit '/config\.xml/d' Makefile.in &&
  sedit 's/pcreposix_regcomp/pcre_compile/' configure &&
  default_build &&
  if ! [  -f /etc/mman.conf  ]; then
    install  -m 640  config.xml  /etc/mman.conf
  fi

) > $C_FIFO 2>&1
