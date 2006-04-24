if [ "$FAAD_CVS" = "n" ]; then
	patch -p0 < ${SCRIPT_DIRECTORY}/Makefile.am.patch  &&
	patch -p0 < ${SCRIPT_DIRECTORY}/gcc-3.4.patch
else
	OPTS="$OPTS --with-drm"
	patch -p1 < ${SCRIPT_DIRECTORY}/faad2-enable-drm.patch
fi	                                               &&
/bin/sh ./bootstrap                                &&
OPTS="$OPTS --with-mp4v2"                          &&
if [ "$XMMS" != "y" ]; then
  OPTS="$OPTS --without-xmms"
fi  &&
default_build
