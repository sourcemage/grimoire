local BLIST=""                                    &&
local BL                                          &&
if list_find "${BOOST_LIBS}" "all" ; then
  BLIST=""
else
  local SEP=" --with-"                            &&
  for BL in $BOOST_LIBS $BOOST_OPTS1 ;do
    BL=${BL// /}                                  &&
    BLIST="${BLIST}${SEP}${BL}"
  done
fi                                                &&
#if ! list_find "$BOOST_LIBS" "python"  &&
#   ! list_find "$BOOST_OPTS1" "python" ; then
#   BLIST="$BLIST --without-python"
#fi
OPTS="$OPTS $BLIST"                               &&
CXXFLAGS="$CXXFLAGS"                              \
bjam -q                                           \
     --prefix=${INSTALL_ROOT}/usr                 \
     -sTOOLS=gcc                                  \
     "-sBUILD=${BOOST_VARIANT## }"                \
     --layout=system                              \
     $OPTS
