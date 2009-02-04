create_account nginx &&

./configure --prefix="$INSTALL_ROOT/etc/nginx" \
         --conf-path="$INSTALL_ROOT/etc/nginx/nginx.conf" \
         --sbin-path="$INSTALL_ROOT/usr/sbin/nginx" \
          --pid-path="$INSTALL_ROOT/var/run/nginx.pid" \
              --user=nginx \
             --group=nginx \
     --http-log-path="$INSTALL_ROOT/var/log/nginx/access.log" \
    --error-log-path="$INSTALL_ROOT/var/log/nginx/error.log" \
                     $OPTS &&

make
