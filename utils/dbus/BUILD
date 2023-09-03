if [[ "${DBUS_BRANCH}" == "devel" ]]; then
  OPTS="runtime_dir=${TRACK_ROOT}/run ${OPTS}" &&
  if [ "$DBUS_SELINUX" == "y" ]; then
     OPTS="selinux=enabled ${OPTS}"
  fi &&
  # Glib2 is used for regression tests and can cause unnecessary build failure
  # when we're in a chain where libffi just has been updated and glib2 not yet.
  # Other solution would be to unnecessarily depend on glib2, or even
  # dbus-glib, which just smells too circular.
  OPTS="user_session=true modular_tests=disabled ${OPTS}"
else
  OPTS="--runstatedir=${TRACK_ROOT}/run ${OPTS}" &&
  if [ "$DBUS_SELINUX" == "y" ]; then
     OPTS="--enable-selinux ${OPTS}"
  fi  &&
  OPTS="--enable-user-session --disable-modular-tests ${OPTS}"
fi &&

create_account  messagebus  &&

default_build &&

if [[ "${DBUS_BRANCH}" == "stable" ]] &&
   is_depends_enabled "${SPELL}" "doxygen"; then
  doxygen
fi
