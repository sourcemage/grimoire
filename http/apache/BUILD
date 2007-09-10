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
