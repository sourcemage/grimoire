# prevent install of init scripts and Mac OS X localization bundle dir
OPTS="--without-rcdir --without-bundledir $OPTS" &&

# set language options
if [[ $EXTRA_LANG == n ]]; then
  OPTS="--without-languages $OPTS"
else
  if [[ $CUPS_LANG == all ]]; then
    OPTS="--with-languages $OPTS"
  else
    OPTS="--with-languages=$CUPS_LANG $OPTS"
  fi
fi &&

OPTS="--libdir=$INSTALL_ROOT/usr/lib $CUPS_OPTS $OPTS"  &&
OPTS="$OPTS CC=gcc CXX=g++" &&
OPTS+=" --disable-static" &&

# needed for dbus 1.14
if is_depends_enabled $SPELL dbus;then
  OPTS+=" --with-dbusdir=$INSTALL_ROOT/usr/share/dbus-1"
fi &&

default_build
