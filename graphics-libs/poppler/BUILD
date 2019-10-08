if is_depends_enabled $SPELL qtbase;then
 QTP+=":${INSTALL_ROOT}/opt/qt5"
fi &&
export CMAKE_PREFIX_PATH=$QTP &&
OPTS+=" $XPDF_HEADERS -DBUILD_CPP_TESTS=0 ${POPPLER_OPTS}" &&
sed -i "/SYSTEM/d" test/CMakeLists.txt glib/CMakeLists.txt &&
default_build
