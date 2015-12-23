cd  "${SOURCE_DIRECTORY}"/comm-*  &&

THUNDERBIRD_HOME="${INSTALL_ROOT}"/usr/lib/thunderbird &&
export  MOZ_THUNDERBIRD="1"   &&

#
# No fast optimization for Mozilla, bit us so many times...
# This used to default to -O2, but that produces crashing firefox for
# sobukus with gcc-5.2.0; -Os seems more safe for Mozilla stuff.
CFLAGS="${CFLAGS//-O2/-Os}"      &&
CXXFLAGS="${CXXFLAGS//-O2/-Os}"  &&
CFLAGS="${CFLAGS//-O3/-Os}"      &&
CXXFLAGS="${CXXFLAGS//-O3/-Os}"  &&

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

make_single  &&
# A frivolous hack to fix that:
# OSError: [Errno 2] No such file or 
#                 directory:  '/usr/src/thunderbird-31.2.0/comm-esr31/mozilla/thunderbird-build'
ln -sf ../thunderbird-build mozilla/
make -f client.mk build &&
make_normal
