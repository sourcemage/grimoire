if  [  "$CVS"  ==  "y"  ];  then
  ./autogen.sh  --prefix=${INSTALL_ROOT}/usr           \
          --sysconfdir=${INSTALL_ROOT}/etc             \
       --localstatedir=${INSTALL_ROOT}/var             \
              --mandir=${INSTALL_ROOT}/usr/share/man   \
             --infodir=${INSTALL_ROOT}/usr/share/info  \
                       $OPTS                           &&
  make
else
  if    [  "$( installed_version db  |  cut  -c1  )"  ==  "4"  ]
  then  sedit  "s/db-3/db-4/g"  configure
        sedit  "s/db-3/db-4/g"  configure.in
        sedit  "s/@DB_LIBS@/-ldb-4/"  doc/Makefile.in
  else  sedit  "s/@DB_LIBS@/-ldb-3/"  doc/Makefile.in
  fi  &&
  OPTS="$OPTS --disable-error-on-warning" &&
  default_build
fi
