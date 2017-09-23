if is_depends_enabled $SPELL qt4;then
 QTP=/opt/qt4
fi&&
if is_depends_enabled $SPELL qtbase;then
 QTP+=":/opt/qt5"
fi&&
export CMAKE_PREFIX_PATH=$QTP &&
OPTS+=" $XPDF_HEADERS -DCMAKE_BUILD_TYPE=$KDE_BUILD_TYPE" &&
OPTS+=" -DBUILD_GTK_TESTS=0 -DBUILD_QT4_TESTS=0 -DBUILD_CPP_TESTS=0 " &&
OPTS+=" -DBUILD_QT5_TESTS=0" &&
cmake_build
