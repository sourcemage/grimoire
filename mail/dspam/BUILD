create_account dspam &&

OPTS="--with-dspam-home="${DSPAM_HOME}" \
     --with-dspam-group=dspam \
--with-dspam-home-group=dspam \
          --with-logdir="${DSPAM_LOG}" \
              --disable-mysql4-initialization \
                        $DSPAM_OPTS \
                        $OPTS" &&

if is_depends_enabled $SPELL $(get_spell_provider $SPELL MAIL-TRANSPORT-AGENT) ; then
  OPTS="--with-dspam-mode=4511 $OPTS"
fi &&

STORAGE_DRIVERS='hash_drv' &&
if is_depends_enabled $SPELL sqlite ; then
STORAGE_DRIVERS="$STORAGE_DRIVERS,sqlite3_drv"
fi &&
if is_depends_enabled $SPELL sqlite2 ; then
STORAGE_DRIVERS="$STORAGE_DRIVERS,sqlite_drv"
fi &&
if is_depends_enabled $SPELL $(get_spell_provider $SPELL MYSQL) ; then
STORAGE_DRIVERS="$STORAGE_DRIVERS,mysql_drv"
fi &&
if is_depends_enabled $SPELL postgresql ; then
STORAGE_DRIVERS="$STORAGE_DRIVERS,pgsql_drv"
fi &&
OPTS="--with-storage-driver=$STORAGE_DRIVERS $OPTS" &&

case "$DSPAM_SCALE" in
  "None") OPTS="--disable-large-scale --disable-domain-scale $OPTS" ;;
  "Large Scale") OPTS="--enable-large-scale --disable-domain-scale $OPTS" ;;
  "Domain Scale") OPTS="--enable-domain-scale --disable-large-scale $OPTS" ;;
esac  &&

default_build
