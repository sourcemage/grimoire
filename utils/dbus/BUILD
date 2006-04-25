if [ "$DBUS_SELINUX" == "y" ]; then
   OPTS="--enable-selinux  $OPTS"
fi  &&

OPTS="$DBUS_GTK2   \
      $DBUS_PYREX  \
      $OPTS"       &&

create_account  messagebus  &&
make_single                 &&
default_build               &&
make_normal
