if [  "$( installed_version db  |  cut  -c1  )"  ==  "4"  ]
then  sedit  "s/db-3/db-4/g"  configure
      sedit  "s/@DB_LIBS@/-ldb-4/"  doc-tools/Makefile.in
else  sedit  "s/@DB_LIBS@/-ldb-3/"  doc-tools/Makefile.in
fi                                                              &&

default_build
