(

  prepare_install              				&&
  python setup.py install --prefix=/usr 		&&

  mkdir -p /usr/doc/spambayes  				&& 
  /bin/cp $SOURCE_DIRECTORY/*.txt /usr/doc/spambayes/	

) > $C_FIFO 2>&1
