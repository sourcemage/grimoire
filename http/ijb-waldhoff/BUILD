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

  for file in blocklist imagelist cookiefile saclfile.ini \
      	      config forward strust.ini
  do
  [  -f  $ETC/$file  ]  ||  cp  $file  $ETC
  done

)
