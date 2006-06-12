  if  spell_ok  sendmail;  then
    patch  -p0  <  ${SCRIPT_DIRECTORY}/Makefile.sendmail.patch
  else
    patch  -p0  <  ${SCRIPT_DIRECTORY}/Makefile.other.patch
  fi                                                            &&

default_build
