create_group   gerbera  &&
create_account gerbera  &&

CFLAGS="${CFLAGS//-ffast-math}" &&
CXXFLAGS="${CXXFLAGS//-ffast-math}" &&
CFLAGS="${CFLAGS//-Ofast/-O2}" &&
CXXFLAGS="${CXXFLAGS//-Ofast/-O2}" &&

# zippp project is unmaintained and fails to build
OPTS="-DWITH_ZIP=OFF ${OPTS}" &&

default_build
