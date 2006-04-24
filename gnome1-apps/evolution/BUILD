(
   case $VERSION in 
     1.0.3)  cd camel
             patch  -p0  <  $SCRIPT_DIRECTORY/evolution-1.0.3.patch
             cd $SOURCE_DIRECTORY
             ;;
   esac

   mkdir  evolution-db3                                         &&
   cd  db-$DBVERSION/build_unix                                 &&
   ../dist/configure  --prefix=$SOURCE_DIRECTORY/evolution-db3  \
                      --disable-dynamic                         &&
   
   make                                                         &&
   make  install                                                &&

   cd  $SOURCE_DIRECTORY                                        &&

   case $WITH_LDAP in
     y|Y|j|J) mkdir evolution-openldap &&
              cd openldap-$LDAPVERSION &&
	      ./configure --prefix=$SOURCE_DIRECTORY/evolution-openldap \
	                  --enable-slapd=no                     \
			  --enable-slurpd=no                    \
	                  --enable-shared=no                    &&
	      make depend                                       &&
	      make                                              &&
	      make install                                      &&

	      OPTS="$OPTS --with-openldap=$SOURCE_DIRECTORY/evolution-openldap \
	            --with-static-ldap=yes"
	      ;;
	   *) OPTS="$OPTS --with-openldap=no"
	      ;;
   esac	                                                        &&

   cd $SOURCE_DIRECTORY                                         &&
  
   sedit s/"nsslibs=\"-lssl3 -lsmime3 -lnss3\""/"nsslibs=\"-lssl3 -lsmime3 -lnss3 -lsoftokn3\""/ \
	configure                                               &&

   OPTS="$OPTS --with-db3=$SOURCE_DIRECTORY/evolution-db3"      &&

   default_build

) > $C_FIFO 2>&1
