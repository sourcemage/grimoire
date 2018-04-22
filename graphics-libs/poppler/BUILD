if is_depends_enabled $SPELL qtbase;then
 QTP+=":${INSTALL_ROOT}/opt/qt5"
fi &&
export CMAKE_PREFIX_PATH=$QTP &&
OPTS+=" $XPDF_HEADERS -DBUILD_CPP_TESTS=0" &&
default_build
