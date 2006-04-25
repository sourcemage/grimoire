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
      make $EXTRA_MAKE_OPTIONS || return 1
    ;;
    2.[024]*)
      echo "making for a 2.4 kernel"  &&
      make dep    &&
      case  $kernel_arch  in
        sparc*)  make $EXTRA_MAKE_OPTIONS vmlinux  ||  return  1  ;;
           ppc)  make $EXTRA_MAKE_OPTIONS vmlinux  ||  return  1  ;;
            sh)  make $EXTRA_MAKE_OPTIONS zImage  ||  return  1  ;;
             *)  make $EXTRA_MAKE_OPTIONS bzImage  ||  return  1  ;;
      esac  &&
      make $EXTRA_MAKE_OPTIONS modules || return 1
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
