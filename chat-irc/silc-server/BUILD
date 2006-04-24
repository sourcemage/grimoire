 if [ "$IPV6" == "y" ]
      then OPTS="$OPTS --enable-ipv6"
 fi
 
 ./configure  --prefix=/usr               \
               --sysconfdir=/etc/silc      \
               --localstatedir=/var/run    \
	       --with-logsdir=/var/log	   \
	       --with-simdir=/usr/lib/silc-server \
	       --with-docdir=/usr/doc/silc-server/doc \
	       --with-helpdir=/usr/share/silc/help \
	       $OPTS		      &&	
  make 
