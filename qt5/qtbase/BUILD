
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
             -no-rpath \
             -reduce-relocations -reduce-exports $OPTS -v &&
make

