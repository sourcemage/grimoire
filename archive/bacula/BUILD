# 'sqlite' stays for old semi-deprecated sqlite2 spell
OPTS=${OPTS//sqlite/sqlite3} &&

OPTS="$BACULA_CLIENT $OPTS" &&
OPTS="--with-scriptdir=$INSTALL_ROOT/etc/bacula \
      --with-working-dir=$INSTALL_ROOT/var/bacula \
      $OPTS" &&

if [[ $BACULA_BRANCH == scm ]]; then
  cd bacula
fi &&

default_build
