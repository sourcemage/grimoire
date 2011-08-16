#not installing in /usr/lib because there could be some clashes with
#other libs.
OPTS="$OPTS --build=$ARK $MATHCORE $MATHMORE $REFLEX $CINTEX $ROOFIT   \
$CERNLIB $GDML $MINUIT2 $TABLE $UNURAN $XROOTD"                        &&
OPTS="$OPTS --enable-builtin-lzma"                                     &&
./configure --prefix=${TRACK_ROOT}/usr                                 \
            --etcdir=${TRACK_ROOT}/etc/root                            \
            --libdir=${TRACK_ROOT}/usr/lib/root                        \
            --incdir=${TRACK_ROOT}/usr/include/root                    \
            --datadir=${TRACK_ROOT}/usr/share/root                     \
            --docdir=${TRACK_ROOT}/usr/share/doc/${SPELL}              \
            --mandir=${TRACK_ROOT}/usr/share/man/man1                  \
            $OPTS                                                     &&

make

