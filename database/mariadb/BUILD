create_account mariadb &&

OPTS="$MARIADB_OPTS $OPTS" &&
CFLAGS="${CFLAGS//-ffast-math}" &&

if [[ $MARIADB_BRANCH == 5.5 ]] || [[ $MARIADB_BRANCH == 10.1 ]]; then
  if [[ $MARIA_TESTS == n ]]; then
    OPTS="-DWITH_UNIT_TESTS=OFF -DINSTALL_MYSQLTESTDIR=OFF $OPTS"
  else
    OPTS="-DWITH_UNIT_TESTS=ON -DINSTALL_MYSQLTESTDIR=share/mysql/mysql-test $OPTS"
  fi &&

  if [[ $MARIA_BENCH == n ]]; then
    OPTS="-DINSTALL_SQLBENCHDIR=OFF $OPTS"
  else
    OPTS="-DINSTALL_SQLBENCHDIR=share/mysql/sql-bench $OPTS"
  fi &&

  OPTS="-DDEFAULT_CHARSET=$MARIADB_CHARSET \
        -DMYSQL_DATADIR=${INSTALL_ROOT}/var/lib/mariadb \
        -DINSTALL_PLUGINDIR=lib/mysql/plugin \
        -DINSTALL_SCRIPTDIR=bin \
        -DINSTALL_SUPPORTFILESDIR=share/mysql \
        -DINSTALL_MYSQLSHAREDIR=share/mysql \
        -DINSTALL_DOCDIR=share/doc/mariadb \
        -DINSTALL_DOCREADMEDIR=share/doc/mariadb \
        -DINSTALL_MANDIR=share/man \
        $OPTS" &&

  if [[ $MARIADB_ENGINES == none ]] || [[ $MARIADB_ENGINES == all ]]; then
    if [[ $MARIADB_BRANCH == 5.5 ]] || [[ $MARIADB_BRANCH == 10.1 ]]; then
      for engine in $MARIADB_ENGINES; do
        OPTS="-DWITH_${engine^^}_STORAGE_ENGINE=OFF $OPTS"
      done
    else
      OPTS="-DWITH_${MARIADB_ENGINES^^} $OPTS"
    fi
  else
    for engine in $MARIADB_ENGINES; do
      OPTS="-DWITH_${engine^^}_STORAGE_ENGINE=ON $OPTS"
    done
  fi &&

  cmake_build
else
  local LD_PRELOAD_OLD="$LD_PRELOAD" &&
  unset LD_PRELOAD &&
  CFLAGS="$CFLAGS -DUSE_OLD_FUNCTIONS" &&

  if glibc_is_nptl; then
    OPTS="--with-named-thread-libs=-lpthread $OPTS" &&
    CPPFLAGS="$CPPFLAGS -D_GNU_SOURCE"
  fi &&

  OPTS="--with-mysqld-user=mariadb \
        --with-charset=$MARIADB_CHARSET \
        --with-plugins=${MARIADB_ENGINES// /,} \
        --localstatedir=${INSTALL_ROOT}/var/lib/mariadb \
        --enable-assembler \
        --enable-thread-safe-client \
        --with-readline \
        $OPTS" &&

  default_build &&

  LD_PRELOAD="$LD_PRELOAD_OLD" &&
  make
fi
