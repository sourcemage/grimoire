message "Target list:$QEMU_ARCHS"  &&

./configure --build=$BUILD             \
           --prefix=$INSTALL_ROOT/usr  \
       --sysconfdir=$INSTALL_ROOT/etc  \
    --localstatedir=$INSTALL_ROOT/var  \
      --target-list="$QEMU_ARCHS"      \
                    $OPTS              &&

make
