if [[ $PROFTPD_DEVEL == "n" ]]; then
  if [[ -z $PROFTPD_CAPS ]]; then
      CFLAGS=${CFLAGS/-fPIC}                                          &&
      CFLAGS=${CFLAGS/-DPIC}                                          &&
      CXXFLAGS=${CXXFLAGS/-fPIC}                                      &&
      CXXFLAGS=${CXXFLAGS/-DPIC}                
  fi
fi                                                                    &&

cd  modules                                                           &&

if  grep  -q  'mod_radius'  ${DEPENDS_CONFIG}/proftpd;  then
  if  !  [  -e  mod_radius.c  ];  then
    ln  -s  ../contrib/mod_radius.c
  fi
fi                                                                    &&

if  grep  -q  'mod_ratio'  ${DEPENDS_CONFIG}/proftpd;  then
  if  !  [  -e  mod_ratio.c  ];  then
    ln  -s  ../contrib/mod_ratio.c
  fi
fi                                                                    &&

if  grep  -q  'mod_readme'  ${DEPENDS_CONFIG}/proftpd;  then
  if  !  [  -e  mod_readme.c  ];  then
    ln  -s  ../contrib/mod_readme.c
  fi
fi                                                                    &&

if  grep  -q  'mod_rewrite'  ${DEPENDS_CONFIG}/proftpd;  then
  if  !  [  -e  mod_rewrite.c  ];  then
    ln  -s  ../contrib/mod_rewrite.c
  fi
fi                                                                    &&

if  grep  -q  'mod_tls'  ${DEPENDS_CONFIG}/proftpd;  then
  if  !  [  -e  mod_tls.c  ];  then
    ln  -s  ../contrib/mod_tls.c
  fi
fi                                                                    &&

if  grep  -q  'mod_wrap'  ${DEPENDS_CONFIG}/proftpd;  then
  if  !  [  -e  mod_wrap.c  ];  then
    ln  -s  ../contrib/mod_wrap.c
  fi
fi                                                                    &&

if  grep  -q  'proftpd:openldap:on'  ${DEPENDS_STATUS};  then
  if  !  [  -e  mod_ldap.c  ];  then
    ln  -s  ../contrib/mod_ldap.c
  fi
fi                                                                    &&

if  grep  -q  'proftpd:mysql:on'  ${DEPENDS_STATUS};  then
  if  !  [  -e  mod_sql.c  ];  then
    ln  -s  ../contrib/mod_sql.c
  fi                                                                  &&
  if  !  [  -e  mod_sql_mysql.c  ];  then
    ln  -s  ../contrib/mod_sql_mysql.c
  fi
fi                                                                    &&

if  grep  -q  'proftpd:postgresql:on'  ${DEPENDS_STATUS};  then
  cd  ../contrib
  sedit  's:<pgsql/libpq-fe.h>:<libpq-fe.h>:'  mod_sql_postgres.c     &&
  cd  ../modules
  if  !  [  -e  mod_sql.c  ];  then
    ln  -s  ../contrib/mod_sql.c
  fi                                                                  &&

  if  !  [  -e  mod_sql_postgres.c  ];  then
    ln  -s  ../contrib/mod_sql_postgres.c
  fi
fi                                                                    &&

cd  ${SOURCE_DIRECTORY}

sedit  "s/	standalone/	inetd/"  sample-configurations/basic.conf  &&

OPTS="$PROFTPD_CAPS ${OPTS//^/:}"                                     &&

./configure  --prefix=${INSTALL_ROOT}/usr                             \
             --sysconfdir=${INSTALL_ROOT}/etc                         \
             --localstatedir=${INSTALL_ROOT}/var/run                  \
             --mandir=$INSTALL_ROOT/usr/share/man                     \
             --enable-shadow                                          \
             ${OPTS}                                                  &&

sedit  's:RUN_DIR.*"/var/run/proftpd":RUN_DIR "/var/run":'  config.h  &&
sedit  's:rundir=/var/run/proftpd:rundir=/var/run:'  Make.rules       &&

make
