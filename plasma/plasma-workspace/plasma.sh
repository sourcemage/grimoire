#!/bin/bash
if [ "$USER" != "root" ];then

# setup KDE5 environment for SMGL
export QTDIR=/opt/qt5
export KF5=$QTDIR
export PATH+=":$KF5/bin"
export XDG_CONFIG_DIRS=/etc/xdg
export QT_PLUGIN_PATH+=:$KF5/lib/plugins

export QML2_IMPORT_PATH=$KF5/lib/qml
export QML_IMPORT_PATH=$QML2_IMPORT_PATH
export XCURSOR_PATH=$KF5/share/icons:~/.icons:/usr/share/icons:/usr/share/pixmaps

# temporary runtime directories
export XDG_RUNTIME_DIR=${TMPDIR-/tmp}/plasma-$USER

# Ensure that they exist
mkdir -p $XDG_RUNTIME_DIR

fi

# if already in kde4, need a separate dbus session for kf5
# eval `dbus-launch`
# before using kf5, need to run:
#    kbuildsycoca5
# if kwin is already running, use the following command
# kwin_x11 --replace &

