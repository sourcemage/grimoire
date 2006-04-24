(

  # Patch for Bug #3255
  patch  -p1  <  ${SCRIPT_DIRECTORY}/gcc3.3.patch            &&

  sedit  's/automake /automake -a /'  make_configure         &&
  sedit  's/void UCvsFolders::DeleteAllItems(UTREEITEM root = 0L)/void UCvsFolders::DeleteAllItems(UTREEITEM root)/' common/UCvsFolders.cpp  &&

  unset  CFLAGS             &&
  unset  CXXFLAGS           &&

  ./make_configure          \
      --prefix=/usr  $OPTS  &&

  cd  cvsunix               &&
  ./configure               \
      --prefix=/usr  $OPTS  &&
  cd  ..                    &&
  make                      &&
  prepare_install           && 
  make  install

) > $C_FIFO 2>&1
