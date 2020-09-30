OPTS+=" $QT_DEBUG             \
      $QT_DECL                \
      $QT_PCH                 \
      $QT_EXAMPLE examples    \
      $QT_TESTS tests         \
      $QT_ACCESS              \
      --linker=$QT_LINKER"    &&
cd $SOURCE_DIRECTORY &&
sizeopt= &&
if list_find "$CXXFLAGS" -Os; then
  sizeopt=-optimize-size
fi &&
./configure  -opensource -confirm-license \
             -prefix $QT5DIR  -platform  linux-g++  \
             -reduce-relocations -reduce-exports $sizeopt \
             $OPTS -v &&
make
