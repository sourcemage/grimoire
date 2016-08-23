create_account nginx &&

persistent_add TEMP_DIR &&
local TEMP_DIR="$INSTALL_ROOT/var/spool/nginx" &&

if list_find "$NGINX_MODULES" "push"; then
  OPTS="--add-module=$SOURCE_DIRECTORY3 $OPTS"
fi &&
if list_find "$NGINX_MODULES" "auth_ldap"; then
  OPTS="--add-module=$SOURCE_DIRECTORY4 $OPTS"
fi &&
if list_find "$NGINX_MODULES" "dav_ext"; then
  OPTS="--add-module=$SOURCE_DIRECTORY5 $OPTS"
fi &&

if [[ $NGINX_SYSLOG == y ]]; then
  OPTS="--add-module=$SOURCE_DIRECTORY/syslog $OPTS"
fi &&

./configure --prefix="$INSTALL_ROOT/etc/nginx" \
         --conf-path="$INSTALL_ROOT/etc/nginx/nginx.conf" \
         --sbin-path="$INSTALL_ROOT/usr/sbin/nginx" \
          --pid-path="$INSTALL_ROOT/var/run/nginx.pid" \
     --http-log-path="$INSTALL_ROOT/var/log/nginx/access.log" \
    --error-log-path="$INSTALL_ROOT/var/log/nginx/error.log" \
              --user=nginx \
             --group=nginx \
--http-client-body-temp-path="$TEMP_DIR/client_body_temp" \
      --http-proxy-temp-path="$TEMP_DIR/proxy_temp" \
    --http-fastcgi-temp-path="$TEMP_DIR/fastcgi_temp" \
      --http-uwsgi-temp-path="$TEMP_DIR/uwsgi_temp" \
       --http-scgi-temp-path="$TEMP_DIR/scgi_temp" \
                             $NGINX_OPTS \
                             $OPTS &&

make
