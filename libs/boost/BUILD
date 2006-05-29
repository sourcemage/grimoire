BLIST="--with-libraries="                             &&
for BL in $BOOST_LIBS;do
  BL=${BL// /}                                        &&
  BLIST="${BLIST}${SEP}${BL}"                         &&
  SEP=,
done                                                  &&
OPTS="$BLIST $OPTS"                                   &&
export CXXFLAGS="$CFLAGS"                             &&
./configure --prefix=${INSTALL_ROOT}/usr              \
                     $OPTS                            &&
make
