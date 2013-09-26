cd  "${SOURCE_DIRECTORY}"/comm-*  &&

THUNDERBIRD_HOME="${INSTALL_ROOT}"/usr/lib/thunderbird &&
export  MOZ_THUNDERBIRD="1"   &&

#
# No fast optimization for Mozilla, bit us so many times...
#
CFLAGS="${CFLAGS//-Os/-O2}"      &&
CXXFLAGS="${CXXFLAGS//-Os/-O2}"  &&
CFLAGS="${CFLAGS//-O3/-O2}"      &&
CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

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
make -f client.mk build &&
make_normal
