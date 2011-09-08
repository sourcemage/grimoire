#!/bin/sh
if [ "$USER" != "root" ];then
# setup KDE4 environment for SMGL

export PATH=/usr/bin/qt4:$PATH
export KDEDIR=$INSTALL_ROOT/usr
export KDEDIRS=$KDEDIR
export KDE_DATA_DIRS=$KDEDIR/share
export PATH=$KDEDIR/bin:$PATH
export XDG_CONFIG_DIRS=/etc/xdg
export QT_PLUGIN_PATH=$KDEDIR/lib/plugins
export LD_LIBRARY_PATH=$KDEDIR/lib:$LD_LIBRARY_PATH
export PKG_CONFIG_PATH=$KDEDIR/lib/pkgconfig:$PKG_CONFIG_PATH
#export KDE_COLOR_DEBUG=1

# this will keep the kde3/4 desktops separate
export KDEHOME=$HOME/.kde4

# temporary runtime directories
export KDETMP=${TMPDIR-/tmp}/kde4-$USER
export KDEVARTMP=/var/tmp/kde4cache-$USER

# Ensure that they exist
mkdir -p $KDEDIR $KDETMP $KDEVARTMP
fi



