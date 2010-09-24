# Remove -ffast-math from CFLAGS, gives problems when building internal SQLite,
# or QtWebkit which forces building it... probably a buildsystem bug.
CFLAGS="${CFLAGS/-ffast-math}"

QTDIR=$INSTALL_ROOT/usr &&

OPTS="$QT_DEBUG               \
      $QT_NIS                 \
      $QT_XRAMA               \
      $QT_GIF                 \
      $QT_EXCEPT              \
      $QT_PCH                 \
      $QT_STL                 \
      $QT_QT3                 \
      $QT_DEMO demos          \
      $QT_EXAMPLE examples    \
      $QT_TOOLS tools         \
      $QT_TRANS translations  \
      $QT_WEBKIT              \
      $QT_MEDIA               \
      $QT_GTK                 \
      $QT_ACCESS              \
      $QT_PHONON              \
      $OPTS"                  &&

./configure  -opensource -confirm-license                                     \
             -prefix  "$INSTALL_ROOT/usr"                                     \
             -bindir  "$INSTALL_ROOT/usr/bin/qt4"                             \
             -docdir  "$INSTALL_ROOT/usr/share/doc/qt4"                       \
             -plugindir  "$INSTALL_ROOT/usr/lib/qt4/plugins"                  \
             -sysconfdir  "$INSTALL_ROOT/etc/qt4"                             \
             -translationdir  "$INSTALL_ROOT//usr/share/doc/qt4/translations" \
             -examplesdir  "$INSTALL_ROOT/usr/share/doc/qt4/examples"         \
             -demosdir  "$INSTALL_ROOT/usr/share/doc/qt4/demos"               \
             -datadir  "$INSTALL_ROOT/usr/share/qt4"                          \
             -platform  linux-g++                                             \
             $OPTS                                                            &&

make
