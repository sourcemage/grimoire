(

  sedit  "s:/usr/local/etc/:/etc/:"  oinkmaster.pl		&&
 
  prepare_install					&&

  cp  oinkmaster.pl  /usr/bin/				&&
  chown  snort.snort  /usr/bin/oinkmaster.pl		&&
  if  [  !  -f  /etc/oinkmaster.conf  ];  then 
      cp  oinkmaster.conf  /etc/
  fi

) > $C_FIFO 2>&1
