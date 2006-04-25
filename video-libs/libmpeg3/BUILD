invoke_gcc

# fails to compile with -DPIC -fPIC except on systems that need -fPIC
if [[ "$SMGL_COMPAT_ARCHS[1]" != "x86_64" ]]
then
  CFLAGS=${CFLAGS/-mmmx/}
fi &&
disable_pic  &&

if ! echo $CFLAGS | grep -q -- "-O."; then
  CFLAGS="$CFLAGS -O2"
fi  &&
if echo $CFLAGS | grep -q -- "-mmmx"; then
  USE_MMX=1
else
  USE_MMX=0
fi  &&
make USE_MMX=$USE_MMX
