(
  
 ./configure  --build=${BUILD}				\
	      --prefix=${INSTALL_ROOT}/usr		\
	      --sysconfdir=${INSTALL_ROOT}/etc		\
	      --localstatedir=${INSTALL_ROOT}/var	\
	      ${OPTS}					&&
 
 make							&&

 prepare_install					&&

 make  install

) >  $C_FIFO  2>&1  &&  (

 ln -s $TRACK_ROOT/usr/bin/notification /usr/X11R6/bin/xsystrace 

)
