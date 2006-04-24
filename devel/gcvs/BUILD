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
  make
