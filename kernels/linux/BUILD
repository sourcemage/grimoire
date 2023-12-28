cd  ${LINUX_SOURCE_DIRECTORY}          &&
echo  "This is the version: $VERSION"  &&

# ppc kernels does not support stripping. This apply to both 2.4 kernels and
# 2.6 kernels.
persistent_add IMAGE_TARGET &&
case "${KERNEL_ARCH}" in
  sparc*)
    IMAGE_TARGET=vmlinux
    ;;
  ppc)
    LDFLAGS="${LDFLAGS/-s/}" &&
    IMAGE_TARGET=vmlinux
    ;;
  sh)
    IMAGE_TARGET=zImage
    ;;
  *)
    ;;
esac &&

if [[ -z "$INTERNAL_ISO_VAR" ]] ; then
  eval make $EXTRA_MAKE_OPTIONS $IMAGE_TARGET &&
  eval make $EXTRA_MAKE_OPTIONS modules &&
  LINUX_BRANCH=$(echo ${VERSION} | cut -d. -f1,2) &&
  case "$VERSION" in
    3*)
      if [[ ${LINUX_BRANCH//./} -le 310 ]] && ( grep -q CONFIG_BONDING=m ./.config || grep -q CONFIG_BONDING=y ./.config )
      then
        echo 'Building ifenslave for network bonding...'  &&
        gcc -Wall -O ./Documentation/networking/ifenslave.c -o ifenslave
      fi
    ;;
  esac
else
  # This is for the iso team don't touch
  make scripts/ &&
  make include/linux/version.h &&
  make include/asm || return 1
fi
