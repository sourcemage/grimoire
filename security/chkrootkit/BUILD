(

  make clean  
  make sense                    			&&
  prepare_install               			&&
  cp ./chkrootkit  /usr/bin				&&
  cp ./check_wtmpx /usr/bin				&&
  cp ./chklastlog  /usr/bin				&&
  cp ./chkproc	   /usr/bin				&&
  cp ./chkwtmp     /usr/bin				&&
  cp ./ifpromisc   /usr/bin     			&&
  cp ./strings-static     /usr/bin     			&&
  mkdir            /usr/doc/chkrootkit 1>/dev/null 2>&1 &&
  cp ./COPYRIGHT   /usr/doc/chkrootkit  		&&
  cp ./README*     /usr/doc/chkrootkit  		&&
  cp ./*.lsm       /usr/doc/chkrootkit

) > $C_FIFO 2>&1 
