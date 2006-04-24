(

  cp    makeconfig           makeconfig.original
  sed  "s:/usr/local:/usr:"  makeconfig.original  >  makeconfig

  ./makeconfig  CONFIG=/etc          \
                INETDCONF=/dev/null  \
                SERVICES=/dev/null   &&
  make                               &&
  prepare_install
 
) > $C_FIFO 2>&1  &&  (

  cp  src/ewl          /usr/bin
  cp  src/fetchfile    /usr/bin
  cp  src/pussy        /usr/bin
  cp  src/receive      /usr/bin
  cp  src/sendfile     /usr/bin
  cp  src/sendfiled    /usr/sbin
  cp  src/sendmsg      /usr/bin
  cp  src/utf7encode   /usr/bin
  cp  src/wlock        /usr/bin
  cp  etc/sf_cleanup   /usr/bin
  cp  etc/sfconf       /usr/bin
  cp  etc/sfdconf      /usr/bin
  ln  -sf  utf7encode  /usr/bin/utf7decode
  ln  -sf  sendfile    /usr/bin/sf
  ln  -sf  receive     /usr/bin/rf
  ln  -sf  sendmsg     /usr/bin/sm

  if  !  [  -f  /etc/sendfile.cf  ];  then
    cp  etc/sendfile.cf  /etc
  fi

  if  !  [  -f  /etc/sendfile.deny  ];  then
    cp  etc/sendfile.deny  /etc
  fi

)
