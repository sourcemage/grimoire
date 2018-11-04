#!/bin/sh
if [ "$USER" != "root" ];then

# setup SDDM environment for SMGL
QTDIR=/opt/qt5
export XDG_CONFIG_DIRS=/etc/xdg
export XDG_DATA_DIRS=$QTDIR/share:/usr/share
export QT_PLUGIN_PATH=$QTDIR/plugins:$QT_PLUGIN_PATH

export QML2_IMPORT_PATH=$QTDIR/qml
export QML_IMPORT_PATH=$QML2_IMPORT_PATH
export XCURSOR_PATH=$QTDIR/share/icons:~/.icons:/usr/share/icons:/usr/share/pixmaps

# temporary runtime directories
export XDG_RUNTIME_DIR=${TMPDIR-/tmp}/sddm-$USER

# Ensure that they exist
mkdir -p $XDG_RUNTIME_DIR
fi



