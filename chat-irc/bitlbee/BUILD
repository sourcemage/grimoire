# BUILD file required because of --etcdir path
# no --sysconfdir is recognized by the bitlbee Makefile

./configure --build=$BUILD \
            --prefix=/usr  \
            --etcdir=/etc/bitlbee \
            $BITLBEE_OPTS $OPTS

make

if [[ "$BITLBEE_BITLBEED" == y ]] ; then
	(cd ${SOURCE_DIRECTORY}/utils && gcc bitlbeed.c -o bitlbeed)
fi
