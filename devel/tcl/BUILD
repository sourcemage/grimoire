cd  $SOURCE_DIRECTORY/unix         &&
OPTS="$OPTS  --enable-threads"     &&
default_build                      &&
mv ../doc/{,Tcl_}Thread.3          &&
sed -i \
  -e "s,^TCL_BUILD_LIB_SPEC='-L.*/unix,TCL_BUILD_LIB_SPEC='-L${TRACK_ROOT}/usr/lib," \
  -e "s,^TCL_SRC_DIR='.*',TCL_SRC_DIR='${TRACK_ROOT}/usr/lib/$SPELL${VERSION%.*}/include'," \
  -e "s,^TCL_BUILD_STUB_LIB_SPEC='-L.*/unix,TCL_BUILD_STUB_LIB_SPEC='-L${TRACK_ROOT}/usr/lib," \
  -e "s,^TCL_BUILD_STUB_LIB_PATH='.*/unix,TCL_BUILD_STUB_LIB_PATH='${TRACK_ROOT}/usr/lib," \
  -e "s,^TCL_LIB_FILE='libtcl${VERSION%.*}..TCL_DBGX..so',TCL_LIB_FILE=\"libtcl${VERSION%.*}\$\{TCL_DBGX\}.so\"," \
  tclConfig.sh
