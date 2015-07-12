if [ $VBOXHARD == "n" ]; then
  OPTS="--disable-hardening $OPTS"
fi &&

OPTS="--disable-docs $OPTS" &&
if [[ ${BUILD%%-*} == "x86_64" ]]; then
  OPTS="--disable-vmmraw $OPTS"
fi &&

OPTS="--with-qt-dir=${TRACK_ROOT}/opt/qt4/ $OPTS"

./configure $OPTS  &&
source ./env.sh  &&
PATH=${TRACK_ROOT}/opt/qt4/bin:$PATH kmk all
