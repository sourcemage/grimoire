cd $SOURCE_DIRECTORY/mozilla* &&

FIREFOX_HOME="$INSTALL_ROOT/usr/lib/firefox" &&
export  MOZ_PHOENIX=1 &&

#
# No fast optimization for Mozilla, bit us so many times...
#
CFLAGS="${CFLAGS//-Os/-O2}"      &&
CXXFLAGS="${CXXFLAGS//-Os/-O2}"  &&
CFLAGS="${CFLAGS//-O3/-O2}"      &&
CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

#
# -ffast-math breaks plugins
#
CFLAGS="${CFLAGS//-ffast-math/}"      &&
CXXFLAGS="${CXXFLAGS//-ffast-math/}"  &&
 
echo ac_add_options --enable-optimize=-O2 >> .mozconfig  &&

make_single  &&
make -f client.mk build &&
make_normal
