OPTS="--with-charset=$MSQL_CHARSET $OPTS" &&

if  list_find "$MSQL_ENGINES" "none"  ;  then
   OPTS="--without-archive-storage-engine    \
         --without-berkeley-db               \
         --without-blackhole-storage-engine  \
         --without-example-storage-engine    \
         --without-federated-storage-engine  \
         --without-innodb                    \
         --without-ndbcluster                \
         $OPTS"
else
  if  list_find "$MSQL_ENGINES" "ARCHIVE"  ;  then
    OPTS="--with-archive-storage-engine $OPTS"
  else
    OPTS="--without-archive-storage-engine $OPTS"
  fi                                                     &&
  if  ! list_find "$MSQL_ENGINES" "BerkeleyDB"  ;  then
    OPTS="--without-berkeley-db $OPTS"
  fi                                                     &&
  if  list_find "$MSQL_ENGINES" "BLACKHOLE"  ;  then
    OPTS="--with-blackhole-storage-engine $OPTS"
  else
    OPTS="--without-blackhole-storage-engine $OPTS"
  fi                                                     &&
  if  list_find "$MSQL_ENGINES" "EXAMPLE"  ;  then
    OPTS="--with-example-storage-engine $OPTS"
  else
    OPTS="--without-example-storage-engine $OPTS"
  fi                                                     &&
  if  list_find "$MSQL_ENGINES" "FEDERATED"  ;  then
    OPTS="--with-federated-storage-engine $OPTS"
  else
    OPTS="--without-federated-storage-engine $OPTS"
  fi                                                     &&
  if  list_find "$MSQL_ENGINES" "InnoDB"  ;  then
    OPTS="--with-innodb $OPTS"
  else
    OPTS="--without-innodb $OPTS"
  fi                                                     &&
  if  list_find "$MSQL_ENGINES" "ndbcluster"  ;  then
    OPTS="--with-ndbcluster $OPTS"
  else
    OPTS="--without-ndbcluster $OPTS"
  fi
fi                                                       &&

OPTS="$MSQL_SERVER $MSQL_EMBED $OPTS"                    &&
CFLAGS="${CFLAGS//-ffast-math}"                          &&

create_account mysql                                     &&

local LD_PRELOAD_OLD="$LD_PRELOAD"                       &&
unset  LD_PRELOAD                                        &&
export CFLAGS="$CFLAGS -DUSE_OLD_FUNCTIONS"              &&

if glibc_is_nptl; then
  OPTS="$OPTS --with-named-thread-libs=-lpthread"        &&
  export CPPFLAGS="$CPPFLAGS -D_GNU_SOURCE"
fi  &&
OPTS="$OPTS --with-mysqld-user=mysql  --without-bench    \
        --localstatedir=${INSTALL_ROOT}/var/lib/mysql    \
        --enable-assembler --enable-thread-safe-client"  &&
default_build                                            &&

#./configure  --build=$BUILD                             \
#            --prefix=$INSTALL_ROOT/usr                  \
#        --sysconfdir=$INSTALL_ROOT/etc                  \
#            --mandir=$INSTALL_ROOT/usr/share/man        \
#           --infodir=$INSTALL_ROOT/usr/share/info       \
#     --localstatedir=/var/lib/mysql                     \
#  --with-mysqld-user=mysql                              \
#           --without-bench                              \
#            --enable-assembler                          \
#            --enable-thread-safe-client                 \
#                     $OPTS                              &&

export  LD_PRELOAD="$LD_PRELOAD_OLD"                     &&
make  pkglibdir=${TRACK_ROOT}/usr/lib
