. "$GRIMOIRE/FUNCTIONS" &&

create_account nginx &&

persistent_add TEMP_DIR &&
local TEMP_DIR="$INSTALL_ROOT/var/spool/nginx" &&

if list_find "$NGINX_MODULES" "push"; then
  OPTS="--add-module=$SOURCE_DIRECTORY3 $OPTS"
fi &&
if list_find "$NGINX_MODULES" "auth_ldap"; then
  OPTS="--add-module=$SOURCE_DIRECTORY4 $OPTS"
fi &&

if [[ $NGINX_SYSLOG == n ]]; then
  OPTS="--http-log-path=$INSTALL_ROOT/var/log/nginx/access.log \
       --error-log-path=$INSTALL_ROOT/var/log/nginx/error.log \
                        $OPTS"
else
  if is_version_less $VERSION 0.8; then
    OPTS="--with-syslog $OPTS"
  else
    OPTS="--add-module=$SOURCE_DIRECTORY/syslog $OPTS"
  fi
fi &&

if ! is_version_less $VERSION 0.8; then
  OPTS="--http-uwsgi-temp-path=$TEMP_DIR/uwsgi_temp $OPTS" &&
  OPTS="--http-scgi-temp-path=$TEMP_DIR/scgi_temp $OPTS"
fi &&

./configure --prefix="$INSTALL_ROOT/etc/nginx" \
         --conf-path="$INSTALL_ROOT/etc/nginx/nginx.conf" \
         --sbin-path="$INSTALL_ROOT/usr/sbin/nginx" \
          --pid-path="$INSTALL_ROOT/var/run/nginx.pid" \
              --user=nginx \
             --group=nginx \
--http-client-body-temp-path="$TEMP_DIR/client_body_temp" \
      --http-proxy-temp-path="$TEMP_DIR/proxy_temp" \
    --http-fastcgi-temp-path="$TEMP_DIR/fastcgi_temp" \
                             $NGINX_OPTS \
                             $OPTS &&

make_single &&
make &&
make_normal
