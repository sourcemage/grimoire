CFLAGS+=' -fcommon' &&
cd squashfs-tools &&
if [[ "$SQUASHFS_LZMA" == "y" ]]; then
  sedit "s/#XZ_SUPPORT/XZ_SUPPORT/" Makefile
fi &&
if [[ "$SQUASHFS_LZO" == "y" ]]; then
  sedit "s/#LZO_SUPPORT/LZO_SUPPORT/" Makefile &&
  sedit "s:#LZO_DIR = /usr/local:LZO_DIR = /usr:" Makefile
fi &&

make


