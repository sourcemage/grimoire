if list_find "$PROFTPD_OPTS" "--disable-cap"; then
  disable_pic
fi &&

if [[ $XINETD_INSTALLED ]]; then
  sedit "s/	standalone/	inetd/" sample-configurations/basic.conf
fi &&

local SQL_INC="." &&

if list_find "$PROFTPD_MODS" "mod_sql_mysql"; then
  SQL_INC="$SQL_INC:$INSTALL_ROOT/usr/include/mysql"
fi &&

if list_find "$PROFTPD_MODS" "mod_sql_postgres"; then
  SQL_INC="$SQL_INC:$INSTALL_ROOT/usr/include/postgresql"
fi &&

OPTS="${PROFTPD_OPTS} \
      ${OPTS} \
      --localstatedir=$INSTALL_ROOT/var/run \
      --with-modules=${PROFTPD_MODS// /:} \
      --with-includes=${SQL_INC}" &&

make_single &&
default_build &&
make_normal
