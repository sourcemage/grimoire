OPTS="${OPTS} ${OPENSC_LOG}" &&
# Remove -Os from CFLAGS; some optimization enabled by it results in an
# uninitialized variable access.
# [See: https://github.com/OpenSC/OpenSC/issues/2836#issuecomment-1679428391]
CFLAGS="${CFLAGS//-Os/-O2}" &&
default_build
