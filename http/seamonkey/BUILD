cd $SOURCE_DIRECTORY/comm-release &&
MOZILLA_HOME=$INSTALL_ROOT/usr/lib/seamonkey  &&

#
# No fast optimization for Mozilla, bit us so many times...
#
CFLAGS="${CFLAGS//-O3/-O2}"      &&
CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

SEAMONKEY_OPTS="--prefix=$INSTALL_ROOT/usr \
                --with-default-mozilla-five-home=$INSTALL_ROOT/usr/lib/seamonkey \
                --enable-extensions=${SEAMONKEY_EXT// /,} \
                --enable-application=suite \
                --enable-svg \
                --enable-canvas \
                --enable-system-ffi \
                --enable-system-sqlite \
                --with-system-nspr \
                --with-system-nss \
                --with-system-zlib \
                --with-system-jpeg \
                --with-system-libevent \
                --disable-crashreporter \
                --disable-installer \
                --disable-tests \
                --disable-debug \
                $SEAMONKEY_OPTS" &&

# TODO: we don't have recent libpng yet
SEAMONKEY_OPTS="--without-system-png $SEAMONKEY_OPTS" &&

# GNOME support is broken (at least for download manager)
SEAMONKEY_OPTS="--disable-gconf \
                --disable-gnomeui \
                --disable-gnomevfs \
                $SEAMONKEY_OPTS" &&

for o in $SEAMONKEY_OPTS; do
  echo "ac_add_options $o" >> .mozconfig
done &&

make_single &&
make -f client.mk build &&
make_normal
