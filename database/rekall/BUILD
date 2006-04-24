  cp scons/Makefile ./                                  &&
  sed "/^enable/D;/^with-ora/D;/^with-db2/D" < scons/settings.$RK_GUI >settings &&
  echo "with-qt-includes=/usr/include/qt" >> settings   &&
  local PY_VER                                          &&
  PY_VER=`installed_version python|cut -c-3`            &&
  echo "with-python-includes=/usr/include/python${PY_VER}" >> settings     &&
  echo "with-python-libraries=/usr/lib/python${PY_VER}/config" >> settings &&
  echo $OPTS >> settings                                &&
  echo $RK_XBASE >> settings                            &&
  KDEDIR=/usr make config                               &&
  make

