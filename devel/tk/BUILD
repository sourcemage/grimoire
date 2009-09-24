local TCLVERSION="$(echo 'puts [set tcl_version]' | tclsh)" &&
local TCLHDIR="${INSTALL_ROOT}/usr/lib/tcl${TCLVERSION}/include" &&

CFLAGS="${CFLAGS} -I${TCLHDIR}/generic -I${TCLHDIR}/unix"            &&

cd  $SOURCE_DIRECTORY/unix        &&
OPTS="$OPTS --enable-threads"      &&
if [ "$DEVEL" = "y" ]; then
  OPTS="$OPTS --enable-xft"
fi  &&

default_build
