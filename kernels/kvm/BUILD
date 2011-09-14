message "Target list: $KVM_ARCHS"          &&

./configure --prefix=${INSTALL_ROOT}/usr                        \
        --sysconfdir=${INSTALL_ROOT}/etc                        \
      --extra-cflags="${CFLAGS}"                                \
     --extra-ldflags="${LDFLAGS}"                               \
         --kerneldir="/lib/modules/$(get_kernel_version)/build" \
          --disable-werror                                      \
          --disable-xen                                         \
          --target-list="$KVM_ARCHS"     \
          --audio-drv-list="${KVM_DRV}"                         \
          --audio-card-list="${KVM_CARD}"                       \
            $OPTS                                               &&
make  &&

if [[ "$KVM_DIAGTOOLS" == "y" ]]; then
  message "${MESSAGE_COLOR}Building KVM diagnostic/debugging tools...${DEFAULT_COLOR}" &&
  pushd "$SOURCE_DIRECTORY/kvm/test" &&
  ./configure --prefix=$INSTALL_ROOT/usr &&
  make &&
  make kvmtrace
  popd
fi
