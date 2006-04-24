invoke_gcc &&
message "Target list:$QEMU_ARCHS"  &&

 ./configure --build=$BUILD \
--prefix=/usr \
--sysconfdir=/etc \
--localstatedir=/var \
--target-list="$QEMU_ARCHS"
$OPTS &&
make
