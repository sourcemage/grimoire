# fix for a gcc 4.2.0 regression
# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=30052
if [[ $(installed_version gcc) == "4.2.0" ]] ; then
CFLAGS="${CFLAGS/-Os/-O0}"
CXXFLAGS="${CXXFLAGS/-Os/-O0}"
CFLAGS="${CFLAGS/-O/-O0}"
CXXFLAGS="${CXXFLAGS/-O/-O0}"
CFLAGS="${CFLAGS/-O1/-O0}"
CXXFLAGS="${CXXFLAGS/-O1/-O0}"
CFLAGS="${CFLAGS/-O2/-O0}"
CXXFLAGS="${CXXFLAGS/-O2/-O0}"
CFLAGS="${CFLAGS/-O3/-O0}"
CXXFLAGS="${CXXFLAGS/-O3/-O0}"
fi                                                            &&
OPTS="${XORG_SERVER_OPTS}                                     \
      --with-mesa-source=${SOURCE_DIRECTORY}/Mesa-${VERSION2} \
      --with-xkb-output=$TRACK_ROOT/var/lib/xkb               \
      --with-dri-driver-path=$TRACK_ROOT/usr/lib/modules/dri  \
      --disable-xprint                                        \
      --disable-dmx                                           \
      --disable-xwin                                          \
      ${OPTS}"                                                &&
default_build
