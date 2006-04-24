# scons leaves mess behind ...
# intentionally ignore the result of next two commands
rm -rf "$BUILD_DIRECTORY/build"
rm -rf "$BUILD_DIRECTORY/lib"

if [ $OPENAL == y ]
then
	USE_OPENAL="USE_OPENAL=1"
else
	USE_OPENAL="USE_OPENAL=0"
fi  &&

scons \
	$USE_OPENAL                        \
	USE_INTERNATIONAL=1                \
	BUILD_BLENDER_PLAYER=1             \
	BUILD_GAMEENGINE=1
