# XXX Fix version number
OPTS+=" -DOBS_VERSION_OVERRIDE=$VERSION" &&
# XXX obs-filters plugin can't build with -ffast-math
CFLAGS="${CFLAGS//-ffast-math}" &&
OPTS+=' -DENABLE_NEW_MPEGTS_OUTPUT=OFF -DENABLE_BROWSER=OFF \
       -DENABLE_WEBSOCKET=NO -DENABLE_VST=ON -DENABLE_AJA=OFF' &&

if ! is_depends_enabled $SPELL python3 && ! is_depends_enabled $SPELL luajit; then
  OPTS="-DENABLE_SCRIPTING=OFF $OPTS"
fi &&

if is_depends_enabled $SPELL qt6base; then
  OPTS="Qt6_DIR=/opt/qt6/cmake/Qt6 $OPTS"
fi &&
default_build
