local TCLVERSION="$(echo 'puts [set tcl_version]' | tclsh)" &&
local TCLHDIR="${INSTALL_ROOT}/usr/lib/tcl${TCLVERSION}/include" &&

OPTS="--with-tcl=${INSTALL_ROOT}/usr/lib        \
      --with-tclinclude=${TCLHDIR}              \
      ${OPTS}"                                  &&
OPTS="--enable-shared $OPTS"                    &&

CFLAGS="${CFLAGS} -I${TCLHDIR}/generic -I${TCLHDIR}/unix"            &&

message "${MESSAGE_COLOR}running configure${DEFAULT_COLOR}"          &&
default_build_configure                                              &&
message "${MESSAGE_COLOR}running make${DEFAULT_COLOR}"               &&
make_single                                     &&
default_build_make TCLHDIRDASHI="-I${TCLHDIR}/generic -I${TCLHDIR}/unix" &&
make_normal
