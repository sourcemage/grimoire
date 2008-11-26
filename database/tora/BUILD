[[ -z $QTDIR ]] && source /etc/profile.d/qt.sh
QTDIR="${QTDIR:-$INSTALL_ROOT/usr}" &&
PATH="$QTDIR/bin/qt4:$PATH" &&

OPTS="${OPTS} --without-oracle --with-uic=$QTDIR/bin/qt4/uic"  &&
default_build
