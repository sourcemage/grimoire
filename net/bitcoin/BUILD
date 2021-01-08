# Disable tests for faster build
OPTS+=' --disable-tests --disable-gui-tests --disable-bench' &&

db48="$INSTALL_ROOT/opt/db48" &&
CPPFLAGS="$CPPFLAGS -I$db48/include" &&
LDFLAGS="$LDFLAGS -L$db48/lib" &&
default_build
