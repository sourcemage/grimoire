(
patch -p0 < $SCRIPT_DIRECTORY/yafc-autoconf.diff &&
aclocal  -I cf &&
autoheader &&
autoconf &&
automake --add-missing --gnu &&
default_build
) > $C_FIFO 2>&1
