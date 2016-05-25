# Remove -ffast-math from CFLAGS, gives problems when building internal SQLite,
# or QtWebkit which forces building it... probably a buildsystem bug.
CFLAGS="${CFLAGS/-ffast-math}" &&
CFLAGS="$CFLAGS -fno-delete-null-pointer-checks -Wno-deprecated"     &&
CXXFLAGS="$CXXFLAGS -fno-delete-null-pointer-checks -std=gnu++98 -Wno-deprecated" &&

QTDIR=$QT4DIR  &&

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

./configure  -opensource -confirm-license \
             -prefix  "$QT4DIR"   \
             -platform  linux-g++ \
             $OPTS    &&

default_build_make
