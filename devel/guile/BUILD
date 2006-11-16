sedit  "s/extern int inet_aton/\/\/ extern int inet_aton/"  \
       libguile/net_db.c                                    &&

libtoolize -c -f                                            &&
./configure      --prefix=${INSTALL_ROOT}/usr               \
             --sysconfdir=${INSTALL_ROOT}/etc               \
             $OPTS                                          &&
make_single                                                 &&
make                                                        &&
make_normal
