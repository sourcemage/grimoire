KVER=$(get_kernel_version)
make_single  &&
make KVER=$KVER KSRC=$INSTALL_ROOT/lib/modules/$KVER/source ||
make KVER=$KVER KSRC=$INSTALL_ROOT/lib/modules/$KVER/source
make_normal
