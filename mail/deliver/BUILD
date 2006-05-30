  sedit  "s:OSHEADER = os-dummy.h:OSHEADER = os-linux.h:"  Makefile
  sedit  "s:extern void usleep();:/* extern void usleep(); */:" sysdep.c
  sedit  "s:/usr/mail:/var/spool/mail:" conf/finish-os.h
  sedit  "s:/usr/spool/mail:/var/spool/mail:" conf/finish-os.h

  make
