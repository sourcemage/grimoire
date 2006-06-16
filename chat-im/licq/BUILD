  if [ "$LICQ_SVN" == "y" ]; then
	make -f Makefile.cvs
  fi &&
  default_build &&

  if [ "$CDK" == "y" ]; then
  cd  $SOURCE_DIRECTORY/plugins/console     &&
  if [ "$LICQ_SVN" == "y" ]; then
	  make -f Makefile.cvs
  fi            &&
  default_build
  fi            &&

  if  [ "$QTGUI" == "y" ];  then
	cd  $SOURCE_DIRECTORY/plugins/qt-gui	                      &&
	if [ "$LICQ_SVN" == "y" ]; then
		make -f Makefile.cvs
	fi &&
    default_build
  fi &&

  if [ "$EMAIL" == "y" ]; then
	cd $SOURCE_DIRECTORY/plugins/email                          &&
    if [ "$LICQ_SVN" == "y" ]; then
		make -f Makefile.cvs 
    fi                                                          &&
	default_build
  fi &&

     if [ "$MSN" == "y" ] && ! list_find "$OPTS" "--disable-openssl"; then
          cd $SOURCE_DIRECTORY/plugins/msn           &&
       if [ "$LICQ_SVN" == "y" ]; then
	     make -f Makefile.cvs 
       fi                                            &&   
	   default_build
     fi  &&
	
	if [ "$AREP" == "y" ]; then
		cd $SOURCE_DIRECTORY/plugins/auto-reply                     &&
		if [ "$LICQ_SVN" == "y" ]; then
		  make -f Makefile.cvs
		fi                                                             &&
		default_build
	fi &&

	if [ "$RMS" == "y" ]; then
	  cd $SOURCE_DIRECTORY/plugins/rms                            &&
      if [ "$LICQ_SVN" == "y" ]; then
		  make -f Makefile.cvs
      fi &&
	  default_build
	fi &&

  if [ "$XOSD" == "y" ]; then
	cd $SOURCE_DIRECTORY/plugins/osd-${SOURCE7_VERSION} &&
	default_build
  fi
