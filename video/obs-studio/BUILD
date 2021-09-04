# XXX Fix version number
OPTS+=" -DOBS_VERSION_OVERRIDE=$VERSION" &&
# XXX obs-filters plugin can't build with -ffast-math
CFLAGS="${CFLAGS//-ffast-math}" &&
OPTS+=' -DBUILD_BROWSER=OFF -DBUILD_VST=OFF' &&
default_build
