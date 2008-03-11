source /etc/profile.d/qt.sh
if [ $PYQT_BIG == y ];then
  VBIG=-c
fi                                                 &&
persistent_add QMAKESPEC=/usr/share/qt/mkspecs/default/    &&
/bin/echo "yes" | python  ./configure.py  -b  /usr/bin \
   -v /usr/share/sip $VBIG -y qt-mt                &&
make
