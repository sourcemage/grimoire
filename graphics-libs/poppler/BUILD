if is_depends_enabled $SPELL qt4;then
 QTP="${INSTALL_ROOT}/opt/qt4"
fi &&
if is_depends_enabled $SPELL qtbase;then
 QTP+=":${INSTALL_ROOT}/opt/qt5"
fi &&
export CMAKE_PREFIX_PATH=$QTP &&
OPTS+=" $XPDF_HEADERS -DBUILD_CPP_TESTS=0" &&
echo "OPTS=$OPTS" &&
cmake_build
