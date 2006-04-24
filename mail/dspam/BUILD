OPTS="$OPTS $DSPAM_DAEMON" &&

STORAGE_DRIVERS='hash_drv' &&
if [[ "$DSPAM_SQLITE" == y ]]; then STORAGE_DRIVERS="$STORAGE_DRIVERS,sqlite3_drv"; fi &&
if [[ "$DSPAM_DB"     == y ]]; then STORAGE_DRIVERS="$STORAGE_DRIVERS,libdb4_drv" ; fi &&
if [[ "$DSPAM_MYSQL"  == y ]]; then STORAGE_DRIVERS="$STORAGE_DRIVERS,mysql_drv"  ; fi &&
if [[ "$DSPAM_PGSQL"  == y ]]; then STORAGE_DRIVERS="$STORAGE_DRIVERS,pgsql_drv"  ; fi &&
OPTS="$OPTS --with-storage-driver=$STORAGE_DRIVERS" &&

default_build
