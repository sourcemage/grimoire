if [[ $LIBDRM_NV == y ]]; then
  OPTS="--enable-nouveau-experimental-api $OPTS"
fi  &&
if [[ $LIBDRM_INTEL == n ]]; then
  OPTS="--disable-intel $OPTS"
fi  &&
if [[ $LIBDRM_RADEON == y ]]; then
  OPTS="--enable-radeon-experimental-api $OPTS"
fi  &&

default_build &&

if [[ $LIBDRM_LIBS == y ]]; then
  cd ${SOURCE_DIRECTORY}/radeon &&
  make
fi
