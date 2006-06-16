OPTS="$MSQL_SERVER $MSQL_INNODB $MSQL_EMBED $OPTS"       &&

create_account mysql                                     &&

LD_PRELOAD_OLD="$LD_PRELOAD"                             &&
unset  LD_PRELOAD                                        &&
export CFLAGS="$CFLAGS -DUSE_OLD_FUNCTIONS"              &&

if glibc_is_nptl; then
  OPTS="$OPTS --with-named-thread-libs=-lpthread"        &&
  export CPPFLAGS="$CPPFLAGS -D_GNU_SOURCE"
fi  &&
OPTS="$OPTS --with-mysqld-user=mysql  --without-bench    \
        --localstatedir=/var/lib/mysql                   \
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
make  pkglibdir=/usr/lib
