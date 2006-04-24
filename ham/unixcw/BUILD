  if ! [ -e /usr/lib/libqt.so ]; then
     ln -s /usr/lib/libqt-mt.so.3.0.4 /usr/lib/libqt.so
  fi 

  mkdir  /tmp/unixcw_qt
  ln  -s /usr/include/qt  /tmp/unixcw_qt/include
  ln  -s /usr/bin         /tmp/unixcw_qt/bin
  ln  -s /usr/lib/qt      /tmp/unixcw_qt/lib
  export QTDIR=/tmp/unixcw_qt

  ./configure  --prefix=/usr          \
               --sysconfdir=/etc      \
               --localstatedir=/var   \
               $OPTS                  &&
  make  all 
