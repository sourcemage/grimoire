create_account nginx &&

persistent_add TEMP_DIR &&
local TEMP_DIR="$INSTALL_ROOT/var/spool/nginx" &&

./configure --prefix="$INSTALL_ROOT/etc/nginx" \
         --conf-path="$INSTALL_ROOT/etc/nginx/nginx.conf" \
         --sbin-path="$INSTALL_ROOT/usr/sbin/nginx" \
          --pid-path="$INSTALL_ROOT/var/run/nginx.pid" \
              --user=nginx \
             --group=nginx \
--http-client-body-temp-path="$TEMP_DIR/client_body_temp" \
      --http-proxy-temp-path="$TEMP_DIR/proxy_temp" \
    --http-fastcgi-temp-path="$TEMP_DIR/fastcgi_temp" \
             --http-log-path="$INSTALL_ROOT/var/log/nginx/access.log" \
            --error-log-path="$INSTALL_ROOT/var/log/nginx/error.log" \
                             $NGINX_OPTS \
                             $OPTS &&

make_single &&
make &&
make_normal
