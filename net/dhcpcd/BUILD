disable_reject_underlinking &&

OPTS+=" $DHCPD" &&
OPTS+=" --enable-ipv6" &&
./configure --libexecdir=${INSTALL_ROOT}/usr/libexec --dbdir=${INSTALL_ROOT}/var/lib/dhcpcd $OPTS &&
CSTD=gnu99 make DESTDIR="$INSTALL_ROOT"
