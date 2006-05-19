OPTS="$OPTS $DSPAM_DAEMON" &&

STORAGE_DRIVERS='hash_drv' &&
if [[ "$DSPAM_SQLITE" == y ]]; then STORAGE_DRIVERS="$STORAGE_DRIVERS,sqlite3_drv"; fi &&
if [[ "$DSPAM_DB"     == y ]]; then STORAGE_DRIVERS="$STORAGE_DRIVERS,libdb4_drv" ; fi &&
if [[ "$DSPAM_MYSQL"  == y ]]; then 
  STORAGE_DRIVERS="$STORAGE_DRIVERS,mysql_drv" &&
  OPTS="$OPTS --with-mysql-includes=/usr/include/mysql"
fi &&
if [[ "$DSPAM_PGSQL"  == y ]]; then 
  STORAGE_DRIVERS="$STORAGE_DRIVERS,pgsql_drv"  &&
  OPTS="$OPTS --with-pgsql-includes=/usr/include/postgresql"
fi &&
OPTS="$OPTS --with-storage-driver=$STORAGE_DRIVERS" &&

if [[ "$DSPAM_VIRTUAL_USERS" == 'y' ]]; then OPTS="$OPTS --enable-virtual-users" ; fi &&
OPTS="$OPTS $DSPAM_LARGE_SCALE $DSPAM_DOMAIN_SCALE" &&

# no need for $INSTALL_ROOT here
OPTS="$OPTS --with-logdir=/var/log" &&

default_build
