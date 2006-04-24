(

  if    spell_ok  linux-pam;  then  SCHEME="pam"
  elif  spell_ok  shadow;     then  SCHEME="shadow"
                              else  SCHEME="auto"
  fi

  AUTH_SCHEME="--enable-authentication-scheme=$SCHEME"

  sedit "s/ eu / /" docs/Makefile.in

  groupadd  gdm           2>/dev/null
  useradd   gdm  -g  gdm  2>/dev/null

  patch  -p 0  <  $SCRIPT_DIRECTORY/gdm.patch  &&

  ./configure  --prefix=${INSTALL_ROOT}/usr         \
               --localstatedir=${INSTALL_ROOT}/var  \
               --sysconfdir=${INSTALL_ROOT}/etc     \
               $AUTH_SCHEME $OPTS                   &&
  make                                              &&
  prepare_install                                   &&
  make    install                                   &&
  mkdir  -p           ${INSTALL_ROOT}/var/gdm       &&
  chown  -R  gdm:gdm  ${INSTALL_ROOT}/var/gdm       &&
  chmod  750          ${INSTALL_ROOT}/var/gdm

) > $C_FIFO 2>&1
