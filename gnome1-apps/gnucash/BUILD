if  [  "$GNUCASH_SVN"  ==  "n"  ];  then
  if    [  "$( installed_version db  |  cut  -c1  )"  ==  "4"  ]
  then  sedit  "s/db-3/db-4/g"  configure
        sedit  "s/db-3/db-4/g"  configure.in
        sedit  "s/@DB_LIBS@/-ldb-4/"  doc/Makefile.in
  else  sedit  "s/@DB_LIBS@/-ldb-3/"  doc/Makefile.in
  fi
fi  &&

  OPTS="${OPTS} --disable-error-on-warning"

default_build
