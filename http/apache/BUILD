# Berkeley DB 4.1 requires an extra parameter in `open'
#patch -p1 < $SCRIPT_DIRECTORY/db-4.1.diff &&

./configure  --prefix=/usr                     \
             --sysconfdir=/etc/httpd           \
             --localstatedir=/var              \
             --logfiledir=/var/log/httpd       \
             --proxycachedir=/var/cache/httpd  \
             --runtimedir=/var/run/httpd       \
             --enable-module=most              \
             --enable-shared=max               \
             --enable-module=mmap_static       \
             --disable-module=auth_dbm         \
             --with-layout=GNU                 \
             $OPTS                             &&
make
