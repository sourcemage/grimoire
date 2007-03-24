local python_ver=$(installed_version python) &&
OPTS=${OPTS//--with-python/--with-python=\/usr\/include\/python${python_ver:0:3}} &&
OPTS=${OPTS//sqlite/sqlite3} &&
./configure \
  --prefix=$INSTALL_ROOT/usr \
  --sysconfdir=$INSTALL_ROOT/etc/bacula \
  --localstatedir=$INSTALL_ROOT/var \
  --mandir=$INSTALL_ROOT/usr/share/man \
  --infodir=$INSTALL_ROOT/usr/share/info \
  $BACULA_CLIENT \
  $OPTS &&
make
