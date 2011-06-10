cd  $SOURCE_DIRECTORY/comm-2.0      &&
MOZILLA_HOME=$INSTALL_ROOT/usr/lib/seamonkey  &&

#
# Only strip if the user wants us to
#
if  echo  $LDFLAGS  |  grep  -q  --  '-s';  then
  OPTS="--enable-strip $OPTS"
fi  &&

#
# No fast optimization for Mozilla, bit us so many times...
#
CFLAGS="${CFLAGS//-O3/-O2}"      &&
CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

make_single                                                  &&
make -f client.mk build                                      &&
make_normal
