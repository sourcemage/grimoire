bluez-nodes()
{
mknod -m 664 /dev/vhci c 10 250

C=0;
while [ $C -lt 256 ]; do
if [ ! -c /dev/rfcomm$C ]; then
mknod -m 666 /dev/rfcomm$C c 216 $C
fi
C=`expr $C + 1`
done
}
(
./configure --with-kernel=/usr/src/linux		\
		--prefix=/usr				\
		$OPTS					&&
cd $SOURCE_DIRECTORY/drivers				&&
patch -p0 < ${SCRIPT_DIRECTORY}/hci_usb.patch		&&
cd $SOURCE_DIRECTORY					&&
make							&&
prepare_install						&&
make install						&&
if [ ! -c /dev/vhci ]; then
bluez-nodes
fi
) > $C_FIFO 2>&1
