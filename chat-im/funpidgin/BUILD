### had to cook up some pkg-config files for nss and nspr 
CFLAGS="$CFLAGS -I${TRACK_ROOT}/usr/X11R6/include"
export PKG_CONFIG_PATH="${TRACK_ROOT}/usr/include/nss:${TRACK_ROOT}/usr/include/nspr" &&
OPTS="--disable-nm $OPTS" &&
make_single          &&
cd $SOURCE_DIRECTORY &&
NOCONFIGURE=Y ./autogen.sh &&
default_build        &&
cd $SOURCE_DIRECTORY
