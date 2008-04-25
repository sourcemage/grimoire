if [ "$GNOME_SYSTEMTOOLS_NETWORK" == "y" ]; then
   OPTS="$OPTS --enable-network"
else
   OTPS="$OPTS --disable-network"
fi                                  &&

if [ "$GNOME_SYSTEMTOOLS_SERVICES" == "y" ]; then
   OPTS="$OPTS --enable-services"
else
   OTPS="$OPTS --disable-services"
fi                                  &&

if [ "$GNOME_SYSTEMTOOLS_TIME" == "y" ]; then
   OPTS="$OPTS --enable-time"
else
   OTPS="$OPTS --disable-time"
fi                                  &&

if [ "$GNOME_SYSTEMTOOLS_USERS" == "y" ]; then
   OPTS="$OPTS --enable-users"
else
   OTPS="$OPTS --disable-users"
fi                                  &&

if [ "$GNOME_SYSTEMTOOLS_SHARES" == "y" ]; then
   OPTS="$OPTS --enable-shares"
else
   OTPS="$OPTS --disable-shares"
fi                                  &&

if [ "$GNOME_SYSTEMTOOLS_NAUTILUS" == "y" ]; then
   OPTS="$OPTS --enable-nautilus"
else
   OTPS="$OPTS --disable-nautilus"
fi                                  &&

default_build
