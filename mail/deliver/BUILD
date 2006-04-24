(

  sedit  "s:OSHEADER = os-dummy.h:OSHEADER = os-linux.h:"  Makefile
  sedit  "s:extern void usleep();:/* extern void usleep(); */:" sysdep.c
  sedit  "s:/usr/mail:/var/spool/mail:" conf/finish-os.h
  sedit  "s:/usr/spool/mail:/var/spool/mail:" conf/finish-os.h

  make                          &&

  prepare_install               &&

  make install			&&

  mkdir /usr/doc/deliver        &&

  cp INSTALL /usr/doc/deliver   &&
  cp MMDF /usr/doc/deliver      &&
  cp README /usr/doc/deliver    &&
  cp SENDMAIL /usr/doc/deliver  &&
  cp -r samples /usr/doc/deliver

) > $C_FIFO 2>&1

