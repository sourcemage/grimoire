sedit  "s/extern int inet_aton/\/\/ extern int inet_aton/"  \
       libguile/net_db.c                                    &&

libtoolize -c -f                &&
./configure  --prefix=/usr      \
             --sysconfdir=/etc  \
             $OPTS              &&
make_single                     &&
make                            &&
make_normal
