cd $SOURCE_DIRECTORY/comm-release &&
MOZILLA_HOME=$INSTALL_ROOT/usr/lib/seamonkey  &&

#
# No fast optimization for Mozilla, bit us so many times...
#
CFLAGS="${CFLAGS//-O3/-O2}"      &&
CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

#
# No AVX optimization for Mozilla (GCC 4.6/4.7 or XUL bug on
# SandyBridge/IvyBridge CPUs). See PR 52762 on GCC bug tracker.
#
CFLAGS="${CFLAGS//-mavx} -mno-avx" &&
CXXFLAGS="${CXXFLAGS//-mavx} -mno-avx" &&

MOZCONFIG="--prefix=$INSTALL_ROOT/usr \
           --with-default-mozilla-five-home=$INSTALL_ROOT/usr/lib/seamonkey \
           --enable-extensions=${SEAMONKEY_EXT// /,} \
           --enable-application=suite \
           --enable-jemalloc \
           --enable-svg \
           --enable-canvas \
           --enable-system-ffi \
           --enable-system-sqlite \
           --with-pthreads \
           --with-system-nspr \
           --with-system-nss \
           --with-system-zlib \
           --with-system-jpeg \
           --with-system-libevent \
           --disable-crashreporter \
           --disable-installer \
           --disable-updater \
           --disable-tests \
           --disable-debug \
           $SEAMONKEY_OPTS" &&

# TODO: we don't have recent libpng yet
MOZCONFIG="--without-system-png $MOZCONFIG" &&

# GNOME support is broken (at least for download manager)
MOZCONFIG="--disable-gconf \
           --disable-gnomeui \
           --disable-gnomevfs \
           $MOZCONFIG" &&

# multijob build
echo "mk_add_options MOZ_MAKE_FLAGS=\"-j$MAKE_NJOBS\"" >> .mozconfig &&

for o in $MOZCONFIG; do
  echo "ac_add_options $o" >> .mozconfig
done &&

make_single &&
make -f client.mk build &&
make_normal
