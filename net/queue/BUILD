CFLAGS="$CFLAGS -DSYS_SIGLIST_DECLARED"

bzcat ${SCRIPT_DIRECTORY}/queue-1.30.patch.bz2 | patch -p1 &&

aclocal                                                    &&
autoheader                                                 &&
libtoolize --force --copy                                  &&
aclocal                                                    &&
autoconf                                                   &&
automake --foreign --add-missing --copy                    &&

./configure                                                \
    --enable-root                                          \
    --bindir=/usr/bin                                      \
    --sbindir=/usr/sbin                                    \
    --datadir=/etc/queue                                   \
    --localstatedir=/var/lib                               \
    --prefix=/usr                                          \
    $OPTS                                                  &&

make


