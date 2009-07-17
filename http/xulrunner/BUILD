cd "$SOURCE_DIRECTORY/mozilla-1.9.1" &&

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
CFLAGS="${CFLAGS//-O3/-O2}"      &&
CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

#
# -ffast-math breaks plugins
#
CFLAGS="${CFLAGS//-ffast-math/}"      &&
CXXFLAGS="${CXXFLAGS//-ffast-math/}"  &&

./configure --prefix=$INSTALL_ROOT/usr                       \
            --mandir=$INSTALL_ROOT/usr/share/man             \
            --enable-optimize="$CFLAGS"                      \
            $OPTS                                            &&
make_single  &&
make -f client.mk build &&
make_normal
