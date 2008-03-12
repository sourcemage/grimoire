persistent_add CFLAGS="${CFLAGS//-O3/-O2}"      &&
persistent_add CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&
persistent_add MOZ_CO_PROJECT=calendar          &&
persistent_add BUILD_OFFICIAL=1                 &&
persistent_add MOZILLA_OFFICIAL=1               &&

OPTS="--with-pthreads                                                \
      --with-default-mozilla-five-home=$INSTALL_ROOT/usr/lib/$SPELL  \
      --enable-application=calendar                                  \
      --enable-extensions=default                                    \
      --disable-system-cairo                                         \
      --disable-updater                                              \
      --disable-installer                                            \
      --disable-tests                                                \
      --disable-xpfe-components                                      \
      $OPTS"                                                         &&

make_single    &&
default_build
