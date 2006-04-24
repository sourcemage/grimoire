DEST=${INSTALL_ROOT}/usr/share/ted &&
patch -p0 < $SCRIPT_DIRECTORY/mk.diff tedPackage/makefile.in &&
make CONFIGURE_OPTIONS="--prefix=${DEST} $OPTS" compile.shared &&
make package.shared

