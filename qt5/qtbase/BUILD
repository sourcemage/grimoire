
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
      $OPTS"                  &&
cd $SOURCE_DIRECTORY &&

./configure  -opensource -confirm-license \
             -prefix $QT5DIR  -platform  linux-g++  \
             -reduce-relocations -reduce-exports $OPTS -v &&
make

