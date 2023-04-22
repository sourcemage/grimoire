#!/bin/sh

# since qt6 is installed to /opt/qt6, users of qt/qml and qt/plugins need to be findable by qt6
# this espacially applies to much of kde



# for kde6
export XDG_DATA_DIRS=/usr/share:${XDG_DATA_DIRS:-/usr/local/share/:/usr/share/}
export XDG_CONFIG_DIRS=/etc/xdg:${XDG_CONFIG_DIRS:-/etc/xdg}

export QT_PLUGIN_PATH=/usr/lib/plugins:$QT_PLUGIN_PATH
export QML2_IMPORT_PATH=/usr/lib/qml:$QML2_IMPORT_PATH

export QT_QUICK_CONTROLS_STYLE_PATH=/usr/lib/qml/QtQuick/Controls.2/:$QT_QUICK_CONTROLS_STYLE_PATH
