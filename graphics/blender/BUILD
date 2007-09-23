if [ $OPENAL == y ]; then
	USE_OPENAL="WITH_BF_OPENAL=1"
else
	USE_OPENAL="WITH_BF_OPENAL=0"
fi  &&

if [ $OPENEXR == y ]; then
	USE_OPENEXR="WITH_BF_OPENEXR=1"
else
	USE_OPENEXR="WITH_BF_OPENEXR=0"
fi  &&
if [ $FFMPEG == y ]; then
	USE_FFMPEG="WITH_BF_FFMPEG=1"
else
	USE_FFMPEG="WITH_BF_FFMPEG=0"
fi  &&

scons \
	$USE_OPENAL                        \
	$USE_OPENEXR                       \
	$USE_FFMPEG                        \
	WITH_BF_INTERNATIONAL=1            \
	WITH_BF_PLAYER=1                   \
	WITH_BF_GAMEENGINE=1               \
	BF_INSTALLDIR=$SOURCE_DIRECTORY/install  &&
# Do not build outside the default tree because of a bug in makesdna compiling 
#        BF_BUILDDIR=$SOURCE_DIRECTORY/build

install -d ${SOURCE_DIRECTORY}/install/linux2/plugins/include &&
install -m 644 ${SOURCE_DIRECTORY}/source/blender/blenpluginapi/*.h \
    ${SOURCE_DIRECTORY}/install/linux2/plugins/include        &&
cp -a ${SOURCE_DIRECTORY}/release/plugins/* ${SOURCE_DIRECTORY}/install/linux2/plugins &&
make -C ${SOURCE_DIRECTORY}/install/linux2/plugins
