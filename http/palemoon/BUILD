export MOZBUILD_STATE_PATH="${SOURCE_DIRECTORY}/mozbuild" &&
export MOZCONFIG="${SOURCE_DIRECTORY}/mozconfig" &&

#
# No AVX optimization for Mozilla (GCC 4.6/4.7 or XUL bug on
# SandyBridge/IvyBridge CPUs). See PR 52762 on GCC bug tracker.
#
CFLAGS="${CFLAGS//-mavx} -mno-avx" &&
CXXFLAGS="${CXXFLAGS//-mavx} -mno-avx" &&

if list_find "${LDFLAGS}" "-s"; then
  OPTS="--enable-strip --enable-install-strip ${OPTS}"
else
  OPTS="--disable-strip --disable-install-strip ${OPTS}"
fi &&

PM_CONFIG="--prefix=${INSTALL_ROOT}/usr \
           --with-default-mozilla-five-home=${INSTALL_ROOT}/usr/lib/palemoon \
           --with-distribution-id=Palemoon \
           --with-pthreads \
           --enable-official-branding \
           --enable-application=browser \
           --disable-accessibility \
           --disable-parental-controls \
           --disable-jemalloc \
           --disable-websms-backend \
           --disable-crashreporter \
           --disable-installer \
           --disable-updater \
           --disable-update-packaging \
           --disable-tests \
           --disable-debug \
           --disable-debug-symbols \
           ${PALEMOON_OPTS} \
           ${OPTS}" &&

# Using a system-provided NSS library is currently not supported
PM_CONFIG="--without-system-nss $PM_CONFIG" &&

# TODO: we don't have recent libpng yet
PM_CONFIG="--without-system-png $PM_CONFIG" &&

# multijob build
echo "mk_add_options MOZ_MAKE_FLAGS=\"-j$MAKE_NJOBS\"" >> ${MOZCONFIG} &&

# required for non-duplicated data in the package
echo "mk_add_options MOZ_OBJDIR=${SOURCE_DIRECTORY}/pmbuild" >> ${MOZCONFIG} &&

echo "ac_add_options --enable-optimize=\"${CFLAGS}\"" >> ${MOZCONFIG} &&

for o in $PM_CONFIG; do
  echo "ac_add_options $o" >> ${MOZCONFIG}
done &&

python2 mach build || message "${MESSAGE_COLOR}Re-running mach...${DEFAULT_COLOR}" &&
python2 mach build
