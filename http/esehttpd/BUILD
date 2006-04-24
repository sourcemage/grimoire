(

  patch -p0 < $SCRIPT_DIRECTORY/esehttpd.conf.patch  &&

  ./configure --prefix=${INSTALL_ROOT}/usr  \
          --sysconfdir=${INSTALL_ROOT}/etc  \
       --localstatedir=${INSTALL_ROOT}/var  \
                       $OPTS                 &&
  make                                       &&
  prepare_install                            &&

  mkdir -p /var/log/esehttpd                 &&
  mkdir -p /etc/esehttpd                     &&
  install -m 644 etc/esehttpd.conf /etc/esehttpd/esehttpd.example.conf  &&
  if [ ! -f /etc/esehttpd/mime.types ] ; then
    install -m 644 etc/mime.types /etc/esehttpd/
  fi  &&

  install -m 755 src/eseconf etc/esectl src/esehttpd  \
        src/esepasswd src/esetestclient /usr/sbin/ &&
  if [ ! -d /var/www ] ; then
    mkdir -p /var/www/cgi-bin
    cp -r doc /var/www/html
  fi

) > $C_FIFO 2>&1
