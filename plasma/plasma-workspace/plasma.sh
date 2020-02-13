#!/bin/bash
if [ "$USER" != "root" ];then
# setup KDE5 environment for SMGL
#export QTDIR=/opt/qt5
#export PATH+=":$QTDIR/bin"
#export XDG_CONFIG_DIRS=/etc/xdg
export QT_PLUGIN_PATH=/usr/lib/plugins

export QML2_IMPORT_PATH=/usr/lib/qml
#export XCURSOR_PATH=$QTDIR/share/icons:~/.icons:/usr/share/icons:/usr/share/pixmaps

# temporary runtime directories
export XDG_RUNTIME_DIR=${TMPDIR-/tmp}/plasma-$USER

# Ensure that they exist
mkdir -p $XDG_RUNTIME_DIR -m7700

fi

# if already in kde4, need a separate dbus session for kf5
# eval `dbus-launch`
# before using kf5, need to run:
#    kbuildsycoca5
# if kwin is already running, use the following command
# kwin_x11 --replace &

