if spell_ok systemd; then
  # if systemd is installed, then include this. Needed for systemd to work
  OPTS=" --with-systemdsystemunitdir=${INSTALL_ROOT}/lib/systemd/system"
fi &&
if [ "$DBUS_SELINUX" == "y" ]; then
   OPTS="--enable-selinux  $OPTS"
fi  &&
# Glib2 is used for regression tests and can cause unnecessary build failure
# when we're in a chain where libffi just has been updated and glib2 not yet.
# Other solution would be to unnecessarily depend on glib2, or even
# dbus-glib, which just smells too circular.
OPTS="--without-dbus-glib --disable-modular-tests $OPTS" &&

create_account  messagebus  &&
default_build               &&

if  is_depends_enabled  $SPELL  doxygen; then
  doxygen
fi
