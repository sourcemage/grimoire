  if  !  spell_ok  linuxdoc-tools  ||
      !  spell_ok  tetex;          then
    export  HAVE_SGML2LATEX=no
  fi
  export HAVE_PS2PDF=no

  autoconf                                             &&
  ./configure  --enable-read-both-confs $OPTS          &&
  sedit  "s/examples//"  Makefile                      &&
  sedit  "s/read yes//"     conf/install_conf          &&
  sedit  "s/read yes//"  modules/install_conf          &&
  sedit  "s/PSER=.*/PSER=/"  Make.Rules                &&
  make
