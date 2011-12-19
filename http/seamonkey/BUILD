cd $SOURCE_DIRECTORY/comm-release &&
MOZILLA_HOME=$INSTALL_ROOT/usr/lib/seamonkey  &&

#
# No fast optimization for Mozilla, bit us so many times...
#
CFLAGS="${CFLAGS//-O3/-O2}"      &&
CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

make_single                                                  &&
make -f client.mk build                                      &&
make_normal
