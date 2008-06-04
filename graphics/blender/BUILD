if [[ $OPENAL == y ]]; then
  USE_OPENAL="WITH_BF_OPENAL=1"
else
  USE_OPENAL="WITH_BF_OPENAL=0"
fi &&

if [[ $OPENEXR == y ]]; then
  USE_OPENEXR="WITH_BF_OPENEXR=1"
else
  USE_OPENEXR="WITH_BF_OPENEXR=0"
fi &&

if [[ $ODE == y ]]; then
  sedit "s:LIBDIR + '/ode':\'$INSTALL_ROOT/usr\':" config/linux2-config.py &&
  USE_ODE="WITH_BF_ODE=1"
else
  USE_ODE="WITH_BF_ODE=0"
fi &&

if [[ $FFMPEG == y ]]; then
  USE_FFMPEG="WITH_BF_FFMPEG=1"
else
  USE_FFMPEG="WITH_BF_FFMPEG=0"
fi &&

scons \
	$USE_OPENAL             \
	$USE_OPENEXR            \
	$USE_ODE                \
	$USE_FFMPEG             \
	WITH_BF_INTERNATIONAL=1 \
	WITH_BF_PLAYER=1        \
	WITH_BF_GAMEENGINE=1    \
	BF_INSTALLDIR=$SOURCE_DIRECTORY/install &&

make -C $SOURCE_DIRECTORY/install/plugins
