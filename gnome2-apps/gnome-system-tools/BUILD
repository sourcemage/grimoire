if [ "$BOOT" == "y" ]; then
   OPTS="$OPTS --enable-boot"
else
   OTPS="$OPTS --disable-boot"
fi                                  &&

if [ "$NETWORK" == "y" ]; then
   OPTS="$OPTS --enable-network"
else
   OTPS="$OPTS --disable-network"
fi                                  &&

if [ "$SERVICES" == "y" ]; then
   OPTS="$OPTS --enable-services"
else
   OTPS="$OPTS --disable-services"
fi                                  &&

if [ "$TIME" == "y" ]; then
   OPTS="$OPTS --enable-time"
else
   OTPS="$OPTS --disable-time"
fi                                  &&

if [ "$USERS" == "y" ]; then
   OPTS="$OPTS --enable-users"
else
   OTPS="$OPTS --disable-users"
fi                                  &&

if [ "$DISKS" == "y" ]; then
   OPTS="$OPTS --enable-disks"
else
   OTPS="$OPTS --disable-disks"
fi                                  &&

if [ "$SHARES" == "y" ]; then
   OPTS="$OPTS --enable-shares"
else
   OTPS="$OPTS --disable-shares"
fi                                  &&

default_build
