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

scons \
	$USE_OPENAL                        \
	$USE_OPENEXR                       \
	WITH_BF_INTERNATIONAL=1            \
	WITH_BF_PLAYER=1                   \
	WITH_BF_GAMEENGINE=1               \
	BF_INSTALLDIR=$SOURCE_DIRECTORY/install 
# Do not build outside the default tree because of a bug in makesdna compiling 
#        BF_BUILDDIR=$SOURCE_DIRECTORY/build
