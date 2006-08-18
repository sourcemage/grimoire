local DIRS  &&

DIRS="QT_BASE_DIR=${TRACK_ROOT}/usr \
QT_LIB_DIR=${TRACK_ROOT}/usr/lib/qt \
QT_BIN_DIR=${TRACK_ROOT}/usr/bin \
QT_INCLUDE_DIR=${TRACK_ROOT}/usr/include/qt"  &&

if check_if_xorg_modular_libs qt-x11; then
  DIRS="X11_LIB_DIR=${TRACK_ROOT}/usr/lib $DIRS"
else
  DIRS="X11_LIB_DIR=${TRACK_ROOT}/usr/X11R6/lib $DIRS"
fi  &&

make  $DIRS
