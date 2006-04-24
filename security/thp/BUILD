(
 
  # change def. path and setting
   # everybody is bad gay :)
  sedit  's:GOODNET=:#GOODNET=:'  iptables.rules		&&
   # we provide only ssh
  sedit  's:GOOD_SVCS="80,22":GOOD_SVCS="22":'  iptables.rules	&&
   # no custom listeners
  sedit  's:HPOT_TCP_SVCS=:#HPOT_TCP_SVCS=:'  iptables.rules	&&
   # iptables loc.
  sedit  's:/sbin/iptables:/usr/sbin/iptables:'  iptables.rules	&&
  
  # change path
  sedit  's:/usr/local/:/usr/share/:'  thp.conf			&&
  sedit  's:/usr/local/:/usr/share/:'  logthis			&&
  sedit  's:/usr/local/:/usr/share/:'  lib/smtp.pl.ref		&&

  prepare_install						&&

  # install xinetd scripts
  cd  xinetd.d							&&
  for  FILE  in  `ls`;  do
     if  [  !  -f  /etc/xinetd.d/${FILE}  ];  then
         sedit  's:/usr/local/:/usr/share/:'  ${FILE}		&&
         cp   -v  ${FILE}  /etc/xinetd.d
     fi
  done								&&
  cd  ..							&&

  # copy app. 
  mkdir  -p  /usr/share/thp					&&
  cp  -Rv  * /usr/share/thp/					&&
 
  # create logdir
  mkdir  -p  /var/log/hpot					&&
 
  # fix perm
  chown  nobody.nogroup  /var/log/hpot  -R			&&
  chmod  700  /var/log/hpot	

) >  $C_FIFO  2>&1
