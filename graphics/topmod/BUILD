if [[ -z $QTDIR ]]; then
 source /etc/profile.d/qt.sh
fi &&
QTDIR="${QTDIR:-$INSTALL_ROOT/usr}" &&
PATH="$QTDIR/bin/qt4:$PATH" &&

# missing image and i18n
touch images/color-fill.png &&
touch lang/topmod_es.qm lang/topmod_fr.qm &&

cd include &&
qmake &&
make &&
cd .. &&
qmake &&
make
