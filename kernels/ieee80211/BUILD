local KERNEL_VER=$(get_kernel_version)                       &&

echo y | make KVER=$KERNEL_VER                               &&
echo y | make KVER=$KERNEL_VER patch_kernel                           &&
cd  $INSTALL_ROOT/lib/modules/$KERNEL_VER/build              &&
sed -i 's:.*CONFIG_IEEE80211.*:CONFIG_IEEE80211=m:' .config  &&
echo n | make  oldconfig                                     &&
make  modules
