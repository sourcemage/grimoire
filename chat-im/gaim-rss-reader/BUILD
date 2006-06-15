CFLAGS="-I/usr/include/libxml2/ $CFLAGS"
./configure  --build=$BUILD                     \
             --prefix=/usr                      \
             --sysconfdir=/etc                  \
             --localstatedir=/var               \
             --with-gaim=/usr/include/gaim      \
             $OPTS                              &&
make_single  &&
make         &&
make_normal
