OPTS="--with-charset=$MSQL_CHARSET $OPTS" &&

if  list_find "$MSQL_ENGINES" "none"  ;  then
   OPTS="--without-berkeley-db               \
         --without-plugin-federated          \
         --without-plugin-innodb_plugin      \
         --without-plugin-ndbcluster         \
         $OPTS"
else
  LDFLAGS="${LDFLAGS/-Wl,--as-needed/}" &&

  # Cleanup MSQL_ENGINES
  MSQL_ENGINES=$(echo $MSQL_ENGINES | tr ' ' '\n' | awk '!_[$0]++' | tr '$\n' ' ')

  if  list_find "$MSQL_ENGINES" "ARCHIVE"  ;  then
    PLUGINS="$PLUGINS,archive"
  fi                                                     &&
  if  ! list_find "$MSQL_ENGINES" "BerkeleyDB"  ;  then
    OPTS="--without-berkeley-db $OPTS"
  fi                                                     &&
  if  list_find "$MSQL_ENGINES" "BLACKHOLE"  ;  then
    PLUGINS="$PLUGINS,blackhole"
  fi                                                     &&
  if  list_find "$MSQL_ENGINES" "EXAMPLE"  ;  then
    PLUGINS="$PLUGINS,example"
  fi                                                     &&
  if  list_find "$MSQL_ENGINES" "FEDERATED"  ;  then
    PLUGINS="$PLUGINS,federated"
  else
    OPTS="--without-plugin-federated $OPTS"
  fi                                                     &&
  if  list_find "$MSQL_ENGINES" "InnoDB"  ;  then
    PLUGINS="$PLUGINS,innodb_plugin"
  else
    OPTS="--without-plugin-innodb_plugin $OPTS"
  fi                                                     &&
  if  list_find "$MSQL_ENGINES" "ndbcluster"  ;  then
    PLUGINS="$PLUGINS,ndbcluster" &&
    OPTS="--with-ndb-test $OPTS"
  else
    OPTS="--without-plugin-ndbcluster $OPTS"
  fi
fi                                                       &&

OPTS="$MSQL_SERVER $MSQL_EMBED --with-plugins=$PLUGINS $OPTS"  &&
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

# Fix compiling with gcc 6+ (C++11 and newer)
export CFLAGS=" -std=gnu++98 ${CFLAGS}"                  &&
export CXXFLAGS=" -std=gnu++98 ${CXXFLAGS}"              &&

default_build                                            &&

export  LD_PRELOAD="$LD_PRELOAD_OLD"                     &&
make  pkglibdir=${TRACK_ROOT}/usr/lib
