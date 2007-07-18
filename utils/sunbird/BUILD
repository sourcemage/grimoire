CFLAGS="${CFLAGS//-O3/-O2}"      &&
CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&
MOZ_CO_PROJECT=calendar          &&

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
