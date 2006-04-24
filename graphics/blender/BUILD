# Setup our environment

if [ $OPENAL == y ]
then
	USE_OPENAL="USE_OPENAL=1"
else
	USE_OPENAL="USE_OPENAL=0"
fi  &&

if [ $FTGL == y ]
then
	USE_FTGL="USE_INTERNATIONAL=1 FTGL_INCLUDE=/usr/include/FTGL"
else
	USE_FTGL="USE_INTERNATIONAL=0"
fi  &&

scons \
	$USE_OPENAL                        \
	$USE_FTGL                          \
	BUILD_GAMEENGINE=1                 \
	BUILD_BLENDER_PALYER=1             \
	BUILD_BLENDER_PLUGIN=1             \
	BUILD_BINARY=release

# Build ends with error, if gameengine is not enabled
#        BUILD_GAMEENGINE=0             \
# scons: *** Source `blenderplayer' not found, needed by target `default'.  Stop.
# scons: building terminated because of errors.


# Build ends with error, if blenderplayer is not enabled
#        BUILD_BLENDER_PALYER=0             \

# Does not seem to produce anything ?
#        BUILD_BLENDER_PLUGIN=1             \

# Does not compile, and default is to use SUMO_SOLID combination
#	USE_PHYSICS=ode        \

# Libraries missing ? Maybe it's only for windows ?
#	USE_QUICKTIME=1        \

# Scons seems to screw theese
#  update: 2.35 seems to take theese into account, but I have not tested it
#     extensively yet
#	CCFLAGS="$CFLAGS"      \
#	CXXFLAGS="$CXXFLAGS"   \
#	LDFLAGS="$LDFLAGS"     \
