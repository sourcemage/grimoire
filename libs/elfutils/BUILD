case "$HOST" in
  *-musl)
    LIBS+=" -lfts -lobstack" &&
    export LIBS
  ;;
esac &&
#If these switches are used, they stop distcc and ccache from working
#  We could write wrappers for all of the possible binaries
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST} --build=${BUILD}"
# We really need to disable PIC, also on archs that otherwise need it.
# see
# http://web.archiveorange.com/archive/v/hlgHmPOOA2S1Ez3KjzWJ
disable_pic force &&
# Ensure at least some opts... buld fails with gcc-4.3 without opts.
# When user does -O0, she has to know why...
OPTS+=" --disable-debuginfod" &&
default_build
