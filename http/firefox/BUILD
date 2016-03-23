FIREFOX_HOME="$INSTALL_ROOT/usr/lib/firefox" &&
export  MOZ_PHOENIX=1 &&

unset DBUS_SESSION_BUS_ADDRESS \
        DISPLAY \
        ORBIT_SOCKETDIR \
        SESSION_MANAGER \
        XDG_SESSION_COOKIE \
        XAUTHORITY &&
export LIBGL_ALWAYS_INDIRECT=1

#
# No fast optimization for Mozilla, bit us so many times...
# This used to default to -O2, but that produces crashing firefox for
# sobukus with gcc-5.2.0; -Os seems more safe.
CFLAGS="${CFLAGS//-O2/-Os}"      &&
CXXFLAGS="${CXXFLAGS//-O2/-Os}"  &&
CFLAGS="${CFLAGS//-O3/-Os}"      &&
CXXFLAGS="${CXXFLAGS//-O3/-Os}"  &&

#
# fix symbol check in build scripts, firefox adds -s to LDFLAGS so we can
# remove it here without changing anything...
#
LDFLAGS="${LDFLAGS// -s/}" &&
LDFLAGS="${LDFLAGS//-s /}" &&
LDFLAGS="${LDFLAGS//^-s$/}" &&

#
# Avoid buggy GCC 4.6 AVX code generation, which breaks libxul
#
local gccver=$(gcc -dumpversion) &&
local gccmajor=${gccver%.*.*}    &&
local gccminor=${gccver#*.}      &&
gccminor=${gccminor%.*}          &&

if [[ $gccmajor == "4" ]] && [[ $gccminor -ge "6" ]]; then
  CFLAGS="${CFLAGS//-mavx} -mno-avx"
  CXXFLAGS="${CXXFLAGS//-mavx} -mno-avx"
fi

for option in $OPTS; do
  echo "ac_add_options $option" >> .mozconfig
done &&

local MAKE_TARGET
if [[ $FIREFOX_PGO == y ]]; then
  MAKE_TARGET=profiledbuild &&
  echo "ac_add_options --enable-profile-guided-optimization" >> .mozconfig
else
  MAKE_TARGET=build
fi &&

make_single  &&
make -f client.mk $MAKE_TARGET &&
make_normal
