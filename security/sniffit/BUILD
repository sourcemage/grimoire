(
  #fix for bug 4138
  sedit 's/_32_bit short/_32_bit/' sn_structs.h

  ./configure  --build=${BUILD}				\
 	       --prefix=${INSTALL_ROOT}/usr		\
	       --sysconfdir=${INSTALL_ROOT}/etc		\
	       --localstatedir=${INSTALL_ROOT}/var	\
	       ${OPTS}					&&
 
  make							&&

  prepare_install					&&


  cp  sniffit.5  /usr/share/man/man5/sniffit.5		&&                                              
  cp  sniffit.8  /usr/share/man/man8/sniffit.8		&&                                              
  cp  sniffit    /usr/sbin/sniffit			&&
  
  mkdir  -p  /usr/share/sniffit				&&
  cp  -v  {sniffit-FAQ,PLUGIN-HOWTO,README.FIRST,dns_plugin.plug,dummy_plugin.plug,sample_config_file}  /usr/share/sniffit/
    
) >  $C_FIFO  2>&1  
