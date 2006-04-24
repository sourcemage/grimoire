 if [ "$IPV6" == "y" ]
      then OPTS="$OPTS --enable-ipv6"
 fi
 
  ./configure  --prefix=/usr               \
               --sysconfdir=/etc/silc      \
               --localstatedir=/var/run    \
	       --with-logsdir=/var/log	   \
	       --with-simdir=/usr/lib/silc-client \
	       --with-docdir=/usr/doc/silc-client/doc \
	       --with-helpdir=/usr/share/silc/help \
	       $OPTS		      &&	
  make 
