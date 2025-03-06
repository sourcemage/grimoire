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

# disable end of build notification
export MOZ_NOSPAM=1 &&

# System rustc has no debuginfo
export RUSTFLAGS="-C debuginfo=0" &&

export MOZBUILD_STATE_PATH="${SOURCE_DIRECTORY}/mozbuild" &&

#
# No fast optimization for Mozilla, bit us so many times...
# This used to default to -O2, but that produces crashing firefox for
# sobukus with gcc-5.2.0; -Os seems more safe.
CFLAGS="${CFLAGS//-O[3s]/-O2}"      &&
CXXFLAGS="${CXXFLAGS//-O[3s]/-O2}"  &&

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

if test -z "$FIREFOX_AUDIO"; then
  OPTS+=" --disable-audio-backends"
else
  OPTS+=" --enable-audio-backends=${FIREFOX_AUDIO// /,}"
fi &&

for option in $OPTS; do
  echo "ac_add_options $option"
done  >> .mozconfig &&

echo "mk_add_options MOZ_MAKE_FLAGS=\"-j$((${#DISTCC_HOSTS[*]} * JOBS_PER_HOST + MAKE_NJOBS))\"" \
>> .mozconfig &&
MACH_BUILD_PYTHON_NATIVE_PACKAGE_SOURCE=none ./mach build
