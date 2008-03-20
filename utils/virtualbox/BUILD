./configure $OPTS  &&

# patch to make this spell compiling with libxcursor from xorg-modular grimoire
# this patch must be applied after configure is run
patch -p0 < $SCRIPT_DIRECTORY/Xcursor.patch

source ./env.sh  &&
kmk all
