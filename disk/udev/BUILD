if spell_ok systemd; then
  # if systemd is installed then we need to tell udev to install it's stuff
  OPTS="$OPTS --with-systemdsystemunitdir=${INSTALL_ROOT}/lib/systemd/system"
fi &&
OPTS="--prefix=$INSTALL_ROOT/usr \
      --bindir=$INSTALL_ROOT/sbin \
      --libexecdir=$INSTALL_ROOT/lib \
      $UDEV_OPTS \
      $OPTS" &&

default_build
