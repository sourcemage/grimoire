if  [  "$MAILSPAM_SSL"  =  "y"  ];  then
	CFLAGS="$CFLAGS  -DSPAMC_SSL"	&&
	echo "\n" | perl  Makefile.PL  ENABLE_SSL="yes"
else
	echo "\n" | perl  Makefile.PL 
fi  &&

make
