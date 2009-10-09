if [[ -z $QTDIR && -f /etc/profile.d/qt.sh ]]
then
  source  /etc/profile.d/qt.sh
fi  &&

QTDIR="${QTDIR:-$INSTALL_ROOT/usr}"  &&
PATH="$QTDIR/bin/qt4:$PATH"          &&

qmake  &&
make
