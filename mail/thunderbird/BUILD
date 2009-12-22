cd  $SOURCE_DIRECTORY/comm-1.9.1  &&

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

#
# Forcing SSE for mfpmath causes Thunderbird to segfault on start
#
CFLAGS="${CFLAGS//-mfpmath=sse/}"      &&
CXXFLAGS="${CXXFLAGS//-mfpmath=sse/}"  &&

if  echo $LDFLAGS | grep  -q  '\-s'; then
  OPTS="$OPTS  --enable-strip"
fi  &&

if [[ $THUNDERBIRD_OFFICIAL == y ]]; then
  OPTS="$OPTS --enable-official-branding"
fi

./configure --prefix=${INSTALL_ROOT}/usr     \
            --with-user-appdir=.thunderbird  \
            --enable-application=mail        \
            --enable-static                  \
              $OPTS                          &&

make
