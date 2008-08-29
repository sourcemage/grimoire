if is_depends_enabled $SPELL qt4; then
    OPTS="-DQT_QMAKE_EXECUTABLE=${INSTALL_ROOT}/usr/bin/qt4/qmake -DLRELEASE_EXECUTABLE=${INSTALL_ROOT}/usr/bin/qt4/lrelease $OPTS"
fi &&

OPTS="-DCMAKE_INSTALL_PREFIX=${INSTALL_ROOT}/usr $OPTS"  &&
cmake_build
