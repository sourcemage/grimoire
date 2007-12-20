./configure      &&

# patch to make this spell compiling with libxcursor from xorg-modular
# this patch must be applied after configure is run
if  check_if_xorg_modular_libs ;  then
    cd $SOURCE_DIRECTORY  && 
    patch -p0 < $SCRIPT_DIRECTORY/Xcursor.patch 
fi  && 

source ./env.sh  &&
kmk all
