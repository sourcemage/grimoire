export CFLAGS="${CFLAGS//-O3/-O2}"      &&
export CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&
export MOZ_CO_PROJECT=calendar          &&
export BUILD_OFFICIAL=1                 &&
export MOZILLA_OFFICIAL=1               &&

OPTS="--with-pthreads                                                \
      --with-default-mozilla-five-home=$INSTALL_ROOT/usr/lib/$SPELL  \
      --enable-application=calendar                                  \
      --disable-system-cairo                                         \
      --disable-updater                                              \
      --disable-installer                                            \
      --disable-tests                                                \
      $OPTS"                                                         &&

make_single    &&
default_build
