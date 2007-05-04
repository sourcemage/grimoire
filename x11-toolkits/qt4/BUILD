export QTDIR=$SOURCE_DIRECTORY  &&
export LD_LIBRARY_PATH=$SOURCE_DIRECTORY/lib:$LD_LIBRARY_PATH &&

OPTS="$QT_DEBUG   \
      $QT_NIS     \
      $QT_XRAMA   \
      $QT_GIF     \
      $QT_EXCEPT  \
      $QT_PCH     \
      $QT_QT3     \
      $QT_DEMO    \
      $QT_EXAMPLE \
      $QT_TOOLS   \
      $QT_TRANS   \
      $OPTS"      &&
if [[ x${QT_DEBUG} == "x" ]];then
  OPTS="-no-separate-debug-info ${OPTS}"
fi &&

./configure   -confirm-license                                                             \
                             -prefix $INSTALL_ROOT/usr                                     \
                             -bindir $INSTALL_ROOT/usr/bin/qt4                             \
                             -docdir $INSTALL_ROOT/usr/share/doc/qt4                       \
                             -plugindir $INSTALL_ROOT/usr/lib/qt4/plugins                  \
                             -sysconfdir $INSTALL_ROOT/etc/qt4                             \
                             -translationdir $INSTALL_ROOT//usr/share/doc/qt4/translations \
                             -examplesdir $INSTALL_ROOT/usr/share/doc/qt4/examples         \
                             -demosdir $INSTALL_ROOT/usr/share/doc/qt4/demos               \
                             -datadir $INSTALL_ROOT/usr/share/qt4                          \
                             -platform linux-g++                                           \
                             -stl                                                          \
                             $OPTS                                                         &&

make
