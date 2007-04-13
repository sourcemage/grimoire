export LDFLAGS="$LDFLAGS -lstdc++"
patch -p0 <$SCRIPT_DIRECTORY/config.sub.patch &&
patch -p1 <$SCRIPT_DIRECTORY/guilib-1.1.0-gcc-4.1.x-fix.diff &&
default_build
