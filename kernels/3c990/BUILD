mconf() {

cat << EOF

alias eth0 3c990

EOF

}

/etc/init.d/networking.sh stop

# remove old driver from memory
if  lsmod | grep 3c990; then
  rmmod 3c990
fi

# remove old driver
if [ -f /lib/modules/`installed_version linux`/kernel/net/3c990.o ]; then
  rm -f /lib/modules/`installed_version linux`/kernel/drivers/net/3c990.o
fi

(
# make the driver

if spell_ok linux; then
  VERSION=`installed_version linux`
fi

cd $BUILD_DIRECTORY
prepare_install
make

cp -f 3c990.o /lib/modules/$VERSION/kernel/net/

if [ ! -f /etc/modules.d/3c990 ]; then
  mkdir -p /etc/modules.d
  mconf > /etc/modules.d/3c990
  touch /etc/modules.d/3c990
fi

MOD="/etc/modules.conf"
INC="include /etc/modules.d/3c990"

grep -q "$INC"     $MOD ||
echo    "$INC" >>  $MOD
insmod 3c990
true

/etc/init.d/networking.sh start

) > $C_FIFO 2>&1

# Clean up
rm -rf 3c990.* 3c990img.h README Makefile
