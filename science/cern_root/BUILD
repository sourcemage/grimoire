#not installing in /usr/lib because there could be some clashes with
#other libs.
OPTS="$OPTS --build=$ARK $MATHCORE $MATHMORE $REFLEX $CINTEX $ROOFIT" &&
./configure --prefix=${TRACK_ROOT}/usr                                 \
            --etcdir=${TRACK_ROOT}/etc/root                            \
            --libdir=${TRACK_ROOT}/usr/lib/root                        \
            --incdir=${TRACK_ROOT}/usr/include/root                    \
            --datadir=${TRACK_ROOT}/usr/share/root                     \
            --mandir=${TRACK_ROOT}/usr/share/man/man1                  \
            $OPTS                                                     &&

make

