(

#  sedit 's/trusted.conf/\/etc\/yafp\/trusted.conf/' yafp.conf		&&
#  sedit 's/pattern.conf/\/etc\/yafp\/pattern.conf/' yafp.conf		&&
#  sedit 's/blockurls.conf/\/etc\/yafp\/blockurls.conf/' yafp.conf	&&
#  sedit 's/cookies.conf/\/etc\/yafp\/cookies.conf/' yafp.conf		&&

  prepare_install 							&&

  mkdir -p /etc/yafp							&&
  cp *.conf /etc/yafp							&&
  cp *.conf.* /etc/yafp							&&

  chown root.root *.pl							&&
  mv testurl.pl /usr/bin/testurl					&&
  mv yafp.pl /usr/bin/yafp
  
) > $C_FIFO 2>&1
