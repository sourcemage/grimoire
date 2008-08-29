# gcc34 is only used to compile the dynamic recompiler of virtualbox
OPTS="--with-gcc-compat=${INSTALL_ROOT}/opt/gcc34/bin/gcc $OPTS"
./configure $OPTS  &&

# patch to make this spell compiling with libxcursor from xorg-modular grimoire
# this patch must be applied after configure is run
patch -p0 < $SCRIPT_DIRECTORY/Xcursor.patch

source ./env.sh  &&
kmk all
