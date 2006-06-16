  if [ "$LICQ_CVS" == "y" ]; then
	make -f Makefile.cvs
  fi &&
  ./configure  --prefix=/usr		\
               --sysconfdir=/etc	\
               --localstatedir=/var	\
	       $OPTS			 &&
  make	 &&

  if [ "$CDK" == "y" ]; then
  cd  $SOURCE_DIRECTORY/plugins/console     &&
  if [ "$LICQ_CVS" == "y" ]; then
	  make -f Makefile.cvs
  fi        &&
  ./configure  --prefix=/usr		\
               --sysconfdir=/etc	\
               --localstatedir=/var	     &&
  make
  fi          &&

  if  [ "$QTGUI" == "y" ];  then
	cd  $SOURCE_DIRECTORY/plugins/qt-gui	                      &&
	if [ "$LICQ_CVS" == "y" ]; then
		make -f Makefile.cvs
	fi                                                            &&
	./configure  --prefix=/usr		\
		     --sysconfdir=/etc		\
		     --localstatedir=/var	\
		     $OPTS	                                  &&
	make                                      
   fi                                 &&

	  cd $SOURCE_DIRECTORY/plugins/email                          &&
       if [ "$LICQ_CVS" == "y" ]; then
	  make -f Makefile.cvs 
       fi                                                            &&
	  ./configure --prefix=/usr \
				  --sysconfdir=/etc \
				  --localstatedir=/var \
				  $OPTS &&
	  make                                                        &&

     if ! list_find "$OPTS" "--disable-openssl"; then
          cd $SOURCE_DIRECTORY/plugins/msn           &&
       if [ "$LICQ_CVS" == "y" ]; then
	  make -f Makefile.cvs 
       fi                                            &&   
	  ./configure --prefix=/usr \
                      --sysconfdir=/etc   \
                      --localstatedir=/var  \
                      $OPTS  &&
           make 
      fi  &&

	  cd $SOURCE_DIRECTORY/plugins/auto-reply                     &&
       if [ "$LICQ_CVS" == "y" ]; then
	  make -f Makefile.cvs
       fi                                                             &&
	  ./configure --prefix=/usr \
		      --sysconfdir=/etc \
		      --localstatedir=/var \
			$OPTS &&
	  make                                                        &&

	  cd $SOURCE_DIRECTORY/plugins/rms                            &&
       if [ "$LICQ_CVS" == "y" ]; then
	  make -f Makefile.cvs
       fi
	  ./configure --prefix=/usr \
		       --sysconfdir=/etc \
	               --localstatedir=/var \
			  $OPTS &&
	  make            &&

  if [ "$XOSD" == "y" ]; then
	  cd $SOURCE_DIRECTORY/plugins/osd-1.2.7.5 &&
#	  ./build                                               &&
	  ./configure --prefix=/usr			\
	              --sysconfdir=/etc		\
		      --localstatedir=/var	\
			 $OPTS			&&
	  make
  fi
