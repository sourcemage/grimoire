(

  patch -p1 < $SCRIPT_DIRECTORY/procstatd-1.4.2.config   &&

  sedit  "s/PREFIX=.*$/PREFIX=\/usr/"  Makefile    &&
  sedit  "s/share\///g"                Makefile    &&
  sedit  "s/port = 7881/port = 7885/"  parsecl.c   &&

  make                                             &&
  make  install                                    &&

  if  spell_ok  perl;  then
    cd  webwatch

    install  -m 644  webwatch.config    /etc/webwatch.config.default

    install  -m 755  clean_ipc          /usr/bin
    install  -m 755  clean_procstatd    /usr/bin
    install  -m 755  clean_prog         /usr/bin
    install  -m 755  start_helper       /usr/bin
    install  -m 755  clean_procstatd    /usr/bin
    install  -m 755  webwatchd          /usr/bin

    install  -m 755  -d  /usr/share/procstatd
    for  FILE  in  `ls -1 meter/*` ;
    do
      install  -m 644  $FILE  /usr/share/procstatd
    done
  fi

) > $C_FIFO 2>&1

