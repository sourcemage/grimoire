(

  if  spell_ok  sendmail;  then
    patch  -p0  <  ${SCRIPT_DIRECTORY}/Makefile.sendmail.patch
  else
    patch  -p0  <  ${SCRIPT_DIRECTORY}/Makefile.other.patch
  fi                                                            &&

  make                                    &&
  prepare_install                         &&
  make    install                         &&
  make    install-man                     &&
  mkdir  -p      /etc/mail                &&
  mkdir  -p      /usr/include/drac        &&
  cp  drac.h     /usr/include/drac        &&
  cp  libdrac.a  /usr/lib		  &&
  if  [  -f  /etc/mail/dracd.allow  ];  then
    cp  $SCRIPT_DIRECTORY/dracd.allow  /etc/mail
  fi

) > $C_FIFO 2>&1
