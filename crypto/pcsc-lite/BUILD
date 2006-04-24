OPTS="${OPTS} ${PCSC_MUSCLE} ${PCSC_EXADPU}"

echo ${OPTS} >> /tmp/pcsc.OPTS

./configure \
  --build=$BUILD \
  --host=$BUILD \
  --prefix=$INSTALL_ROOT/usr \
  --sysconfdir=$INSTALL_ROOT/etc \
  --infodir=$INSTALL_ROOT/usr/share/info \
  --mandir=$INSTALL_ROOT/usr/share/man \
  --enable-confdir=$INSTALL_ROOT/etc/pcsc-lite \
  --enable-ipcdir=/var/run/ipc \
  --localstatedir=$INSTALL_ROOT/var \
  --enable-runpid=/var/run \
  $OPTS &&
make
