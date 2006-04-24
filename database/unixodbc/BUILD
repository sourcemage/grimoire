patch -p1 < $SPELL_DIRECTORY/ltdl.diff libltdl/ltdl.c	&&
if  ldd  /usr/lib/libqt-mt.so | grep libodbc | grep -q "not found"; then
OPTS="$OPTS --enable-gui=no"  &&
message "${MESSAGE_COLOR}Temporarily broken qt library detected, disabling gui!"  &&
message "To get the gui back, just recast unixodbc again.${DEFAULT_COLOR}"
fi  &&
default_build
