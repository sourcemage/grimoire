
if is_depends_enabled $SPELL qtbase;then
 export QXMLEDIT_INST_DIR=$QT5DIR/bin
 export QXMLEDIT_INST_LIB_DIR=$QT5DIR/lib
 export QXMLEDIT_INST_INCLUDE_DIR=$QT5DIR/include/qxmledit
 export QXMLEDIT_INST_DOC_DIR=$QT5DIR/share/doc/qxmledit
 export QXMLEDIT_INST_DATA_DIR=$QT5DIR/share/qxmledit
 qt5_build
else
 export "${QT4DIR:-$INSTALL_ROOT/usr}"
 export QXMLEDIT_INST_DIR=$QT4DIR/bin
 export QXMLEDIT_INST_LIB_DIR=$QT4DIR/lib
 export QXMLEDIT_INST_INCLUDE_DIR=$QT4DIR/include/qxmledit
 export QXMLEDIT_INST_DOC_DIR=$QT4DIR/share/doc/qxmledit
 export QXMLEDIT_INST_DATA_DIR=$QT4DIR/share/qxmledit
 qt4_build
fi


