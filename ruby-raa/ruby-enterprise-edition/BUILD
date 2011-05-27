cd $SOURCE_DIRECTORY/source &&

if [[ "$REE_TC" == "y" ]]; then
  TCMALLOC="-ltcmalloc_minimal"
fi &&
if [[ "$REE_DOC" == "y" ]]; then
  OPTS="$OPTS --enable-install-doc"
fi &&
OPTS="$OPTS $REE_OPTS --enable-mbari-api"  &&
./configure --prefix=${INSTALL_ROOT}/usr $OPTS CFLAGS="$CFLAGS" &&
sedit "s/LIBS =/LIBS= \$(PRELIBS) /" Makefile &&
make PRELIBS="-Wl,-rpath,${INSTALL_ROOT}/usr/lib -L${INSTALL_ROOT}/usr/lib $TCMALLOC"
