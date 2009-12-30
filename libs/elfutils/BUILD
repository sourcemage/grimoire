#If these switches are used, they stop distcc and ccache from working
#  We could write wrappers for all of the possible binaries
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST} --build=${BUILD}"
OPTS="$OPTS --program-suffix=.elfutils" &&
disable_pic &&
# Ensure at least some opts... buld fails with gcc-4.3 without opts.
# When user does -O0, she has to know why...
CFLAGS="-O $CFLAGS" &&
default_build
