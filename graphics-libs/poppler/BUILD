if is_depends_enabled $SPELL qtbase;then
 QTP+=":${INSTALL_ROOT}/opt/qt5"
fi &&
export CMAKE_PREFIX_PATH=$QTP &&
OPTS+=" $XPDF_HEADERS -DBUILD_CPP_TESTS=0" &&
# Make it for all on next release
if [[ "${POPPLER_BRANCH}" == "scm" ]]; then
  OPTS="${OPTS/ENABLE_XPDF_HEADERS/ENABLE_UNSTABLE_API_ABI_HEADERS}"
fi &&
sed -i "/SYSTEM/d" test/CMakeLists.txt glib/CMakeLists.txt &&
default_build
