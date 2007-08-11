disable_pic  &&
# remove -O3, as requested by project
CFLAGS=${CFLAGS/-O3/-O2}   &&
if [[ "$FREEDOS" == "y" ]];then
OPTS="--with-fdtarball=$SOURCE2 $OPTS"
else
OPTS="--with-fdtarball=none $OPTS"
fi            &&
default_build

