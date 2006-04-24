cd  ${LINUX_SOURCE_DIRECTORY}          &&
echo  "This is the version: $VERSION"  &&

# ppc kernels does not support stripping. This apply to both 2.4 kernels and
# 2.6 kernels.

case "${kernel_arch}" in
  ppc)
    LDFLAGS="${LDFLAGS/-s/}"
    ;;
esac &&

if [[ -z "$INTERNAL_ISO_VAR" ]] ; then
  case "$VERSION" in
    2.6*)
      echo "making for a 2.6 kernel"  &&
      ARCH="$kernel_arch" make $EXTRA_MAKE_OPTIONS || return 1
    ;;
    2.[024]*)
      echo "making for a 2.4 kernel"  &&
      ARCH="$kernel_arch" make dep    &&
      case  $kernel_arch  in
        sparc*)  ARCH="$kernel_arch"  make $EXTRA_MAKE_OPTIONS vmlinux  ||  return  1  ;;
           ppc)  ARCH="$kernel_arch"  make $EXTRA_MAKE_OPTIONS vmlinux  ||  return  1  ;;
            sh)  ARCH="$kernel_arch"  make $EXTRA_MAKE_OPTIONS zImage  ||  return  1  ;;
             *)  ARCH="$kernel_arch"  make $EXTRA_MAKE_OPTIONS bzImage  ||  return  1  ;;
      esac  &&
      ARCH="$kernel_arch" make $EXTRA_MAKE_OPTIONS modules || return 1
    ;;
    *)
      echo "There is no kernel version: $VERSION"  &&
      return 1
    ;;
  esac
else
  # This is for the iso team don't touch
  make scripts/ &&
  make include/linux/version.h &&
  make include/asm || return 1
fi
