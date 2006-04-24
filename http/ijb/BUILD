(
    
  make                                               &&
  prepare_install                                    &&
  mkdir  -p              /var/log/junkbuster         &&
  mkdir  -p              /etc/junkbuster             &&
  mkdir  -p              /usr/doc/junkbuster         &&
  install -s -m 755 junkbuster /usr/sbin/junkbuster  &&
  cp  -f  junkbuster.1   /usr/man/man8/junkbuster.8  &&
  cp  -f  ijbman.html    /usr/doc/junkbuster         &&
  cp  -f  ijbfaq.html    /usr/doc/junkbuster

) > $C_FIFO 2>&1  &&  (

  ETC="/etc/junkbuster"

  [  -f  $ETC/junkbstr.ini  ]  ||  cp  junkbstr.ini  $ETC
  [  -f  $ETC/sblock.ini    ]  ||  cp  sblock.ini    $ETC
  [  -f  $ETC/scookie.ini   ]  ||  cp  scookie.ini   $ETC
  [  -f  $ETC/saclfile.ini  ]  ||  cp  saclfile.ini  $ETC
  [  -f  $ETC/sforward.ini  ]  ||  cp  sforward.ini  $ETC
  [  -f  $ETC/strust.ini    ]  ||  cp  strust.ini    $ETC
   

)
