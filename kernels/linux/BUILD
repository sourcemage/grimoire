cd  ${LINUX_SOURCE_DIRECTORY}          &&
echo  "This is the version: $VERSION"  &&

# ppc kernels does not support stripping. This apply to both 2.4 kernels and
# 2.6 kernels.

case "${KERNEL_ARCH}" in
  sparc*)
    IMAGE_TARGET=vmlinux
    ;;
  ppc)
    LDFLAGS="${LDFLAGS/-s/}"
    IMAGE_TARGET=vmlinux
    ;;
  sh)
    IMAGE_TARGET=zImage
    ;;
  *)
    IMAGE_TARGET=bzImage
    ;;
esac &&

if [[ -z "$INTERNAL_ISO_VAR" ]] ; then
  case "$VERSION" in
    2.[024]*)
      echo "making deps for a 2.4 kernel"  &&
      make dep    
    ;;
  esac &&
  make $EXTRA_MAKE_OPTIONS $IMAGE_TARGET &&
  make $EXTRA_MAKE_OPTIONS modules &&
  if grep -q CONFIG_BONDING=m ./.config || grep -q CONFIG_BONDING=y ./.config
  then
    gcc -Wall -O -I/usr/src/linux/include ./Documentation/networking/ifenslave.c -o ifenslave
  fi
else
  # This is for the iso team don't touch
  make scripts/ &&
  make include/linux/version.h &&
  make include/asm || return 1
fi
