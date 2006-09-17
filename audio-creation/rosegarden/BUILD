if [[ "$ROSEGARDEN_SOUND" == n ]]; then
  OPTS="nosound=1 noalsa=1 nojack=1 nodssi=1 $OPTS"
fi  &&

echo $OPTS

scons configure prefix=${INSTALL_ROOT}/usr \
datadir=${INSTALL_ROOT}/usr/share \
qtincludes=${TRACK_ROOT}/usr/include/qt \
$OPTS  &&

scons
