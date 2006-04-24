#  sed -i "/^GETVALUE/s/;//" libs/kbase/kb_options.cpp	&&
#  sed -i "/Q_OBJECT/s/;//" libs/kbase/kb_draglist.h	&&
#  sed -i "/Q_OBJECT/s/;//" libs/kbase/kb_optionsdlg.h	&&
#  sed -i "s/};/}/"         db/pgsql/kb_pgsql.cpp	&&

if [ "$DEVEL" == "y" ]; then
  cp scons/Makefile ./                                  &&
  sed "/^enable/D;/^with-ora/D" < scons/settings.$GUI >settings   &&
  echo "with-qt-includes=/usr/include/qt" >> settings             &&
  echo "with-python-includes=/usr/include/python2.4" >> settings  &&
  echo "with-python-libraries=/usr/lib/python2.4/config" >> settings &&
  KDEDIR=/usr make config                               &&
  make
else
  OPTS="--with-gui=$GUI $XBASE $OPTS"                   &&
  patch -p0 < $SPELL_DIRECTORY/conf.diff                &&
  default_build
#  ./configure --prefix=${INSTALL_ROOT}/usr $OPTS 	&&
#  sed -i "s/-pedantic//" libs/extra/Makefile		&&
#  sed -i "s/-pedantic//" libs/kdeplugins/Makefile	&&
#  sed -i "s/-pedantic//" script/python/stub/Makefile    &&
#  sed -i "s/-pedantic//" parts/table2/Makefile          &&
#  sed -i "s/-pedantic//" parts/form/Makefile            &&
#  sed -i "s/-pedantic//" parts/report/Makefile          &&
#  sed -i "s/-pedantic//" parts/query/Makefile           &&
#  sed -i "s/-pedantic//" parts/copier/Makefile          &&
#  sed -i "s/-pedantic//" parts/component/Makefile       &&
#  sed -i "s/-pedantic//" parts/editor/Makefile          &&
#  sed -i "s/-pedantic//" parts/macro/Makefile           
fi                                                      

