disable_stack_clash_protection &&

FIREFOX_HOME="$INSTALL_ROOT/usr/lib/firefox" &&
export  MOZ_PHOENIX=1 &&

unset DBUS_SESSION_BUS_ADDRESS \
        DISPLAY \
        ORBIT_SOCKETDIR \
        SESSION_MANAGER \
        XDG_SESSION_COOKIE \
        XAUTHORITY &&
export LIBGL_ALWAYS_INDIRECT=1 &&

# System rustc has no debuginfo
export RUSTFLAGS="-C debuginfo=0" &&

# harden
LDFLAGS="$LDFLAGS -Wl,-z,now"    &&

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
  CFLAGS="${CFLAGS//-mavx} -mno-avx"     &&
  CXXFLAGS="${CXXFLAGS//-mavx} -mno-avx"
fi

for option in $OPTS; do
  echo "ac_add_options $option" >> .mozconfig
done &&

echo "mk_add_options MOZ_MAKE_FLAGS=\"-j${MAKE_NJOBS:-1}\"" >> .mozconfig &&
./mach build
