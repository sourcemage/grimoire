  if [[ "$LICQ_BRANCH" == "scm" ]]; then
	make -f Makefile.cvs
  fi &&
  default_build &&

  if [[ "$CDK" == "y" ]]; then
    cd  $SOURCE_DIRECTORY/plugins/console     &&
    if [[ "$LICQ_BRANCH" == "scm" ]]; then
      make -f Makefile.cvs
    fi            &&
    default_build
  fi            &&

  if [[ "$QT4GUI" == "y" ]]; then
    cd  $SOURCE_DIRECTORY/plugins/qt4-gui                          &&
    if [[ "$LICQ_BRANCH" == "scm" ]]; then
      make -f Makefile.cvs
    fi &&
    mkdir build &&
    cd    build &&
    QTDIR=/usr &&
    PATH=$QTDIR/bin/qt4:$PATH &&
    export QTDIR=/usr &&
    cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_ROOT/usr .. &&
    make
  fi &&

  if [[ "$EMAIL" == "y" ]]; then
    cd $SOURCE_DIRECTORY/plugins/email                          &&
    if [[ "$LICQ_BRANCH" == "scm" ]]; then
      make -f Makefile.cvs 
    fi                                                          &&
    default_build
  fi &&

  if [[ "$MSN" == "y" ]] && ! list_find "$OPTS" "--disable-openssl"; then
    cd $SOURCE_DIRECTORY/plugins/msn           &&
    if [[ "$LICQ_BRANCH" == "scm" ]]; then
      make -f Makefile.cvs 
    fi                                            &&   
    default_build
  fi  &&
	
  if [[ "$AREP" == "y" ]]; then
    cd $SOURCE_DIRECTORY/plugins/auto-reply                     &&
    if [[ "$LICQ_BRANCH" == "scm" ]; then
      make -f Makefile.cvs
    fi                                                          &&
    default_build
  fi &&

  if [[ "$RMS" == "y" ]]; then
    cd $SOURCE_DIRECTORY/plugins/rms                            &&
    if [[ "$LICQ_BRANCH" == "scm" ]]; then
      make -f Makefile.cvs
    fi &&
    default_build
  fi &&

  if [[ "$XOSD" == "y" ]]; then
    cd $SOURCE_DIRECTORY/plugins/osd-${SOURCE7_VERSION} &&
    default_build
  fi
