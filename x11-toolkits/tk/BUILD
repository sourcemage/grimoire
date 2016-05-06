local TCLVERSION="$(echo 'puts [set tcl_version]' | tclsh)" &&
local TCLHDIR="${INSTALL_ROOT}/usr/lib/tcl${TCLVERSION}/include" &&

CFLAGS="${CFLAGS} -I${TCLHDIR}/generic -I${TCLHDIR}/unix"            &&

cd  $SOURCE_DIRECTORY/unix        &&
OPTS="$OPTS --enable-threads --enable-xft"      &&

default_build &&
sed -i -e "s,^TK_SRC_DIR='.*',TK_SRC_DIR='${TRACK_ROOT}/usr/lib/$SPELL${VERSION%.*}/include'," \
    tkConfig.sh
