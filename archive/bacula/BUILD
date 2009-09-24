local python_ver=$(installed_version python) &&
OPTS=${OPTS//--with-python/--with-python=\/usr\/include\/python${python_ver:0:3}} &&
OPTS=${OPTS//sqlite/sqlite3} &&
OPTS="${OPTS} ${BACULA_CLIENT}" &&
if [ "${BACULA_SCM}" == 'y' ]; then
  cd bacula
fi &&
default_build
