
#I do not understand why this is needed.  Soup doesn't have an option
#for --with-db3. No one else I can find builds with db
#  mkdir  soup-db3                                         &&
#  cd  db-$DBVERSION/build_unix                            &&
#  ../dist/configure  --prefix=$SOURCE_DIRECTORY/soup-db3  \
#                     --disable-dynamic                    &&
#  make                                                    &&
#  make  install                                           &&

#  cd  $SOURCE_DIRECTORY                                   &&

  sedit s/"nsslibs=\"-lssl3 -lsmime3 -lnss3\""/"nsslibs=\"-lssl3 -lsmime3 -lnss3 -lsoftokn3\""/ \
    configure                                             &&

 # OPTS="$OPTS --with-db3=$SOURCE_DIRECTORY/soup-db3"      &&


  ./configure  --build=$BUILD        \
               --prefix=/usr         \
               --sysconfdir=/etc     \
               --localstatedir=/var  \
               --disable-glib2       \
               --disable-gtk-doc     \
               $OPTS                 &&

  # Fix a typo in their generated Makefile...
  sedit  "s:;;: :"  src/libsoup-apache/Makefile  &&

  make 
