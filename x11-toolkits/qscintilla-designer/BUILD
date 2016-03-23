if is_depends_enabled qscintilla qt4; then
  PATH=$QT4DIR/bin:$PATH     &&
  cd designer-Qt4             &&
  qmake                       &&
  make
else
  source /etc/profile.d/qt.sh &&
  cd designer-Qt3             &&
  sedit 's|$(QTDIR)/plugins/designer|$(QTDIR)/lib/qt/plugins/designer|' designer.pro
  qmake
fi
