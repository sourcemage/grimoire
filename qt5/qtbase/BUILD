QTDIR=$INSTALL_ROOT/opt/qt5 &&

# need to specify version in path for gstreamer!!
if is_depends_enabled $SPELL gstreamer;then
  VV=`installed_version gstreamer | cut -c-4`
  OPTS+=" -I$INSTALL_ROOT/usr/include/gstreamer-$VV"
  OPTS+=" -L$INSTALL_ROOT/usr/lib/gstreamer-$VV -lgstreamer-$VV"
fi &&
OPTS="$QT_DEBUG               \
      $QT_NIS                 \
      $QT_XRAMA               \
      $QT_GIF                 \
      $QT_PCH                 \
      $QT_EXAMPLE examples    \
      $QT_TESTS tests         \
      $QT_ACCESS              \
      $QT_AUDIO               \
      $QT_JVS                 \
      $OPTS"                  &&
cd $SOURCE_DIRECTORY &&

./configure  -opensource -confirm-license \
             -prefix $QTDIR  -platform  linux-g++  \
             -reduce-relocations -reduce-exports $OPTS -v &&
make

