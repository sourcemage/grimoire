  rm -rf /tmp/artwiz-fonts                              &&
  cd /tmp                                               &&
  unpack $SOURCE ${MD5[0]}                              &&

(

  prepare_install                                                    &&
  mkdir  -p  "$DIR" 2>/dev/null                                      &&
  install -m 644 -o root -g root /tmp/fluxbox-artwiz-fonts/* "$DIR"  &&
  rm -rf /tmp/fluxbox-artwiz-fonts                                   &&
  mkfontdir "$DIR"

)  >  $C_FIFO
