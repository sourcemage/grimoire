CFLAGS="${CFLAGS/-Wunsafe-loop-optimizations}" &&
CFLAGS="$CFLAGS -Wno-error=format-overflow"    &&
cd generate/unix &&

make_single  &&
if [[ "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" || "${SMGL_COMPAT_ARCHS[1]}" == "em64t" ]]; then
  make BITS=64 HOST=_LINUX iasl
else
  make BITS=32 HOST=_LINUX iasl
fi &&
make_normal
