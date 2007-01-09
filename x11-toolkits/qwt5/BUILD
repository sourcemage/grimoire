export QTDIR=${INSTALL_ROOT}/usr               &&
local QMAKE                                    &&
if spell_ok qt4;then 
  QMAKE=${TRACK_ROOT}/usr/bin/qt4/qmake
else
  QMAKE=${TRACK_ROOT}/usr/bin/qmake
fi                                             &&
$QMAKE qwt.pro                                 &&

make                                           &&
cd designer                                    &&
$QMAKE qwtplugin.pro                           &&
make                                           &&
cd ..
