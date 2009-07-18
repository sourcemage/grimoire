cd "${SOURCE_DIRECTORY}" &&

./configure --prefix=${INSTALL_ROOT}/usr                        \
      --extra-cflags="${CFLAGS}"                                \
     --extra-ldflags="${LDFLAGS}"                               \
         --kerneldir="/lib/modules/$(get_kernel_version)/build" \
          --disable-werror                                      \
            $OPTS                                               &&
make
