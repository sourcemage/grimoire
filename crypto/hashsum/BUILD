invoke_gcc &&
if [[ "$HOST" == x86_64-* ]]; then
  patch -p1 < $SCRIPT_DIRECTORY/hashsum-64-bit.patch
fi &&
make
