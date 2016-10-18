OPTS="-DSYSDIG_VERSION=$VERSION \
      -DENABLE_DKMS=NO \
      $OPTS" &&

export KERNELDIR="/lib/modules/$(get_kernel_version)/build" &&

make_single &&
cmake_build &&
make_normal
