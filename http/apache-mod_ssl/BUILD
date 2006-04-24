export  SSL_BASE=SYSTEM  &&
export  EAPI_MM=SYSTEM   &&

cd  mod_ssl-$VERSION                                &&
./configure  --with-apache=../$SOURCE2_BASE  $OPTS  &&
cd  ../$SOURCE2_BASE                                &&

./configure --prefix=/usr                      \
            --sysconfdir=/etc/httpsd           \
            --localstatedir=/var/lib/httpsd    \
            --logfiledir=/var/log/httpsd       \
            --proxycachedir=/var/cache/httpsd  \
            --runtimedir=/var/run/httpsd       \
            --datadir=/usr/share/httpsd        \
            --enable-module=most               \
            --enable-shared=max                \
            --enable-module=mmap_static        \
            --disable-module=auth_dbm          \
            --enable-rule=EAPI                 \
            --with-layout=GNU                  \
            $OPTS                              &&

make_single  &&

if  [  "$CERTIFICATE"  ==  "y"  ];  then
  make  certificate  TYPE='custom'
else
  make  certificate  TYPE='existing'  CRT=/etc/httpsd/ssl.crt/server.crt
fi &&

#
# need the following to fix the error at
# http://forum.sun.com/thread.jsp?forum=151&thread=18986&tstart=0&trange=15
#
cp  ../mod_ssl-$VERSION/pkg.sslmod/ssl_expr_scan.c  \
                   src/modules/ssl/ssl_expr_scan.c  &&
make         &&
make_normal
