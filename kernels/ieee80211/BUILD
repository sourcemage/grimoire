local KERNEL_VER=$(get_kernel_version)                     &&

echo y | make KVER=$KERNEL_VER                             &&
make KVER=$KERNEL_VER patch_kernel                         &&
cd  $INSTALL_ROOT/lib/modules/$KERNEL_VER/build            &&
echo n | make  oldconfig                                   &&
make  modules
