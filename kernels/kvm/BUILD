cd "${SOURCE_DIRECTORY}" &&

./configure --prefix=${INSTALL_ROOT}/usr                        \
       --qemu-cflags="${CFLAGS}"                                \
      --qemu-ldflags="${LDFLAGS}"                               \
         --kerneldir="/lib/modules/$(get_kernel_version)/build" \
          --disable-werror                                      &&
make
