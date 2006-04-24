OPTS="--disable-avahi $OPTS"   &&
if [ "$GTK_ONLY" == "y" ]; then
     echo "Building without gnome support"   &&
     OPTS="$OPTS --disable-gnome"
else
     echo "Building with gnome support"
fi &&
./configure --prefix=${INSTALL_ROOT}/usr --sysconfdir=${INSTALL_ROOT}/etc  $OPTS &&
make
