cd "$SOURCE_DIRECTORY/mozilla-2.0" &&

XULRUNNER_HOME="$INSTALL_ROOT/usr/lib/xulrunner" &&
export  MOZ_PHOENIX=1 &&

#
# Only strip if the user wants us to
#
if  echo  $LDFLAGS  |  grep  -q  --  '-s';  then
  OPTS="$OPTS  --enable-strip"
fi  &&

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

OPTS="${OPTS} --enable-optimize=-O2" &&


make_single  &&
# workaround for configure not handling --disable-necko-wifi correctly
if [[ $OPTS =~ --disable-necko-wifi ]]; then
  echo ac_add_options --disable-necko-wifi >> .mozconfig
fi &&
make -f client.mk build &&
make_normal
