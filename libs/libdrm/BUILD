if [[ $LIBDRM_AMD == y ]]; then
  OPTS="--enable-amdgpu $OPTS"
else
  OPTS="--disable-amdgpu $OPTS"
fi  &&
if [[ $LIBDRM_NV == y ]]; then
  OPTS="--enable-nouveau $OPTS"
else
  OPTS="--disable-nouveau $OPTS"
fi  &&
if [[ $LIBDRM_INTEL == n ]]; then
  OPTS="--disable-intel $OPTS"
else
  OPTS="--enable-intel $OPTS"
fi  &&
if [[ $LIBDRM_RADEON == y ]]; then
  OPTS="--enable-radeon $OPTS"
else
  OPTS="--disable-radeon $OPTS"
fi  &&
default_build
