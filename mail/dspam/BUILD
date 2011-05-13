create_account dspam &&

OPTS="--with-dspam-home=$INSTALL_ROOT/var/spool/dspam \
     --with-dspam-group=dspam \
--with-dspam-home-group=dspam \
          --with-logdir=$INSTALL_ROOT/var/log/dspam \
                        $DSPAM_OPTS \
                        $OPTS" &&

if is_depends_enabled $SPELL $(get_spell_provider $SPELL MAIL-TRANSPORT-AGENT) ; then
  OPTS="--with-dspam-mode=4511 $OPTS"
fi &&

STORAGE_DRIVERS='hash_drv' &&
if is_depends_enabled $SPELL sqlite ; then
STORAGE_DRIVERS="$STORAGE_DRIVERS,sqlite3_drv"
fi &&
if is_depends_enabled $SPELL db ; then
STORAGE_DRIVERS="$STORAGE_DRIVERS,libdb4_drv"
fi &&
if is_depends_enabled $SPELL $(get_spell_provider $SPELL MYSQL) ; then
STORAGE_DRIVERS="$STORAGE_DRIVERS,mysql_drv"
fi &&
if is_depends_enabled $SPELL postgresql ; then
STORAGE_DRIVERS="$STORAGE_DRIVERS,pgsql_drv"
fi &&
OPTS="--with-storage-driver=$STORAGE_DRIVERS $OPTS" &&

case "$DSPAM_SCALE" in
  "none") ;;
  "Large Scale") OPTS="$OPTS --enable-large-scale" ;;
  "Domain Scale") OPTS="$OPTS --enable-domain-scale" ;;
esac  &&

default_build
