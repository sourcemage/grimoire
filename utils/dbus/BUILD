if [ "$DBUS_SELINUX" == "y" ]; then
   OPTS="--enable-selinux  $OPTS"
fi  &&

create_account  messagebus  &&
make_single                 &&
default_build               &&
make_normal                 &&

if  is_depends_enabled  $SPELL  doxygen; then
  doxygen
fi
