create_account mariadb &&

OPTS="$MADB_OPTS $OPTS" &&
CFLAGS="${CFLAGS//-ffast-math}" &&

local LD_PRELOAD_OLD="$LD_PRELOAD" &&
unset LD_PRELOAD &&
CFLAGS="$CFLAGS -DUSE_OLD_FUNCTIONS" &&

if glibc_is_nptl; then
  OPTS="--with-named-thread-libs=-lpthread $OPTS" &&
  CPPFLAGS="$CPPFLAGS -D_GNU_SOURCE"
fi &&

OPTS="--with-mysqld-user=mariadb \
      --with-charset=$MADB_CHARSET \
      --with-plugins=${MADB_ENGINES// /,} \
      --localstatedir=${INSTALL_ROOT}/var/lib/mariadb \
      --enable-assembler \
      --enable-thread-safe-client \
      $OPTS" &&

default_build &&

LD_PRELOAD="$LD_PRELOAD_OLD" &&
make pkglibdir=${TRACK_ROOT}/usr/lib
