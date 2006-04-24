(
  sedit  "s/\/usr\/local\/pgsql/\/usr/"  Makefile  &&
  make                               &&
  prepare_install                    
  
) > $C_FIFO 2>&1  &&

(                       

  cp pglogd /usr/sbin 
  
  sedit "s/\/var\/log\/pglogd.log/\/var\/log\/pglogd\/pglogd.log/" pglogd.conf
  sedit "s/\/usr\/site\/logs\/pglogd_overflow/\/var\/log\/pglogd\/pglogd_overflow/" pglogd.conf
  [  -e  /etc/pglogd.conf      ]  ||   cp pglogd.conf /etc/pglogd.conf
  chmod o-rwx /etc/pglogd.conf

  mkdir -p /usr/doc/pglogd/
  cp  *.sql /usr/doc/pglogd/
  cp  queries.txt /usr/doc/pglogd
  cp  $SCRIPT_DIRECTORY/pglogd.quick /usr/doc/pglogd

)
