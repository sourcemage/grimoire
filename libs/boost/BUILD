local BLIST=""                                    &&
if list_find "${BOOST_LIBS}" "all" ; then
  BLIST=""
else
  local SEP=" --with-"                            &&
  for BL in $BOOST_LIBS;do
    BL=${BL// /}                                  &&
    BLIST="${BLIST}${SEP}${BL}"
  done
fi                                                &&
OPTS="$OPTS $BLIST"                               && 
CXXFLAGS="$CXXFLAGS"                              \
bjam --prefix=${INSTALL_ROOT}/usr                 \
     -sTOOLS=gcc                                  \
     "-sBUILD=${BOOST_VARIANT}"  \
     --layout=system                              \
     $OPTS
