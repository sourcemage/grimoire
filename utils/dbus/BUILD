if [ "$DBUS_SELINUX" == "y" ]; then
   OPTS="--enable-selinux  $OPTS"
fi  &&

create_account  messagebus  &&
default_build               &&

if  is_depends_enabled  $SPELL  doxygen; then
  doxygen
fi
