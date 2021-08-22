OPTS+=" $QT_DEBUG             \
      $QT_DECL                \
      $QT_PCH                 \
      $QT_EXAMPLE examples    \
      $QT_TESTS tests         \
      $QT_ACCESS              \
      --linker=$QT_LINKER"    &&
# XXX DTLS support depends on DTLSv1_listen having a BIO_ADDR argument which
# isn't supported by LibreSSL (<= 3.3.3 at least).
if is_depends_enabled "$SPELL" libressl; then
  OPTS+=' -no-feature-dtls'
fi &&
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
