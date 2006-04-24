(

  prepare_install &&

  [ -d /usr/lib/$SPELL ] || mkdir /usr/lib/$SPELL 	&&
  [ -d /usr/doc/$SPELL ] || mkdir /usr/doc/$SPELL	&&
  cp -a *.py /usr/lib/$SPELL 				&&
  cp -a getmail /usr/bin/ 				&&
  cp getmail.1 /usr/man/man1/ 				&&

  cp getmailrc-example /usr/doc/$SPELL		   	&&
  cp docs.*            /usr/doc/$SPELL			&&
  cp faq.html          /usr/doc/$SPELL

) > $C_FIFO 2>&1
