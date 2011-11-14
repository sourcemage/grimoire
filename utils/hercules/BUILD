if [[ $HERC_VER == devel ]];then 
  sh autogen.sh                                   
fi
  ./configure  --prefix=/usr                     \
               --exec-prefix=/usr                \
               --sysconfdir=/etc                 \
	       $OPTS				 &&
  make 
