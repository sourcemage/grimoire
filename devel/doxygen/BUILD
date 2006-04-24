  OPTS="$OPTS $ENGLISH"                                                    &&
  sedit  "s/grep fileutils/grep 'Free Software Foundation'/"  ./configure  &&
  sedit  "s/-O2/$CFLAGS/"  tmake/lib/linux-g++/tmake.conf                  &&
  sedit  "s/\$(QTDIR)\/include/\$(QTDIR)\/include\/qt/"  tmake/lib/linux-g++/tmake.conf  &&
  export QTDIR=/usr &&
  ./configure --prefix ${INSTALL_ROOT}/usr  \
              $OPTS          &&
  make                       
