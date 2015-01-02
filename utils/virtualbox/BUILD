if [ $VBOXHARD == "n" ]; then
  OPTS="--disable-hardening $OPTS"
fi &&

OPTS="--disable-docs $OPTS" &&
if [[ ${BUILD%%-*} == "x86_64" ]]; then
  OPTS="--disable-vmmraw $OPTS"
fi &&

./configure $OPTS  &&
source ./env.sh  &&
PATH=${TRACK_ROOT}/usr/bin/qt4:$PATH kmk all
