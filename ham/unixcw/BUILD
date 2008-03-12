  if ! [ -e /usr/lib/libqt.so ]; then
     ln -s $TRACK_ROOT/usr/lib/libqt-mt.so.3.0.4 /usr/lib/libqt.so
  fi 

  mkdir  /tmp/unixcw_qt
  ln -s $TRACK_ROOT/usr/include/qt  /tmp/unixcw_qt/include
  ln -s $TRACK_ROOT/usr/bin         /tmp/unixcw_qt/bin
  ln -s $TRACK_ROOT/usr/lib/qt      /tmp/unixcw_qt/lib
  export QTDIR=/tmp/unixcw_qt

  ./configure  --prefix=/usr          \
               --sysconfdir=/etc      \
               --localstatedir=/var   \
               $OPTS                  &&
  make  all 
