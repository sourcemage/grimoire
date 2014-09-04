if spell_ok systemd; then
  # if systemd is installed, then include this. Needed for systemd to work
  OPTS=" --with-systemdsystemunitdir=${INSTALL_ROOT}/lib/systemd/system"
fi &&
if [ "$DBUS_SELINUX" == "y" ]; then
   OPTS="--enable-selinux  $OPTS"
fi  &&

create_account  messagebus  &&
default_build               &&

if  is_depends_enabled  $SPELL  doxygen; then
  doxygen
fi
