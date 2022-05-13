local  KVER                 &&
KVER=$(get_kernel_version)  &&

make modules \
  -j${MAKE_NJOBS:-1}                             \
             LD=ld.bfd                           \
  KERNEL_MODLIB=$INSTALL_ROOT/lib/modules/$KVER  \
   KERNEL_UNAME=$KVER                            \
         SYSSRC=$INSTALL_ROOT/lib/modules/$KVER/source
