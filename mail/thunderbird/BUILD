cd  $SOURCE_DIRECTORY/mozilla  &&

THUNDERBIRD_HOME=${INSTALL_ROOT}/usr/lib/thunderbird &&
export  MOZ_THUNDERBIRD="1"   &&

#
# No fast optimization for Mozilla, bit us so many times...
#
export  CFLAGS="${CFLAGS//-O3/-O2}"      &&
export  CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

#
# -ffast-math breaks plugins
#
CFLAGS="${CFLAGS//-ffast-math/}"      &&
CXXFLAGS="${CXXFLAGS//-ffast-math/}"  &&

if  echo $LDFLAGS | grep  -q  '\-s'; then
  OPTS="$OPTS  --enable-strip"
fi  &&

./configure --prefix=${INSTALL_ROOT}/usr     \
            --with-user-appdir=.thunderbird  \
            --enable-application=mail        \
            --enable-optimize="$CFLAGS"      \
              $OPTS                          &&

make  &&

if [[ "$BUILD_ENIGMAIL" == 'y' ]]; then
   build/autoconf/make-makefile mailnews/extensions/enigmail &&
   make -C mailnews/extensions/enigmail
fi
