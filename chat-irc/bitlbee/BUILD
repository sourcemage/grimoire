# BUILD file required because of --etcdir path
# no --sysconfdir is recognized by the bitlbee Makefile

export OPTS="$OPTS --etcdir=/etc/bitlbee" &&
./configure --build=$BUILD \
            --prefix=/usr  \
            --etcdir=/etc/bitlbee \
            $BITLBEE_OPTS $OPTS

make
