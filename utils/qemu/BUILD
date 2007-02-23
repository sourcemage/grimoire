message "Target list:$QEMU_ARCHS"  &&

#
# Disable PIC if building soft MMU targets
# Pentium3/4 breaks on building soft MMU, downgrade to pentium-mmx
#
if  list_find  "$QEMU_ARCHS"  *-softmmu;  then
  CFLAGS=${CFLAGS/pentium4/pentium-mmx}  &&
  CFLAGS=${CFLAGS/pentium3/pentium-mmx}  &&
  disable_pic
fi  &&


./configure --build=$BUILD             \
           --prefix=$INSTALL_ROOT/usr  \
       --sysconfdir=$INSTALL_ROOT/etc  \
    --localstatedir=$INSTALL_ROOT/var  \
      --target-list="$QEMU_ARCHS"      \
                    $OPTS              &&

make
