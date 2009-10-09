cd "$SOURCE_DIRECTORY" &&
if [[ ${SMGL_COMPAT_ARCHS[1]} == alpha ]]; then
  scons PREFIX=/usr DEBUG=no ENABLE_OPTIMIZATIONS=yes DIST_TARGET=none
else
  # note: this always compiles for current cpu
  scons PREFIX=/usr DEBUG=no ENABLE_OPTIMIZATIONS=yes
fi
