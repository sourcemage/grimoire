#If these switches are used, they stop distcc and ccache from working
#  We could write wrappers for all of the possible binaries
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST} --build=${BUILD}"
OPTS="$OPTS --program-suffix=.elfutils" &&
default_build
