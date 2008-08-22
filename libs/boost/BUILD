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
if list_find "${BOOST_LIBS}" "graph"              ||
   list_find "${BOOST_LIBS}" "all" ; then
   local EXPAT_INCLUDE=/usr/lib
   local EXPAT_LIBPATH=/usr/include
fi
if list_find "${BOOST_LIBS}" "mpi"                ||
   list_find "${BOOST_LIBS}" "all" ; then
   echo "using mpi ;" > tools/build/v2/user-config.jam
fi                                                &&
OPTS="$OPTS $BLIST"                               &&
echo $OPTS
CXXFLAGS="$CXXFLAGS"                              \
EXPAT_INCLUDE=$EXPAT_INCLUDE                      \
EXPAT_LIBPATH=$EXPAT_LIBPATH                      \
bjam -q                                           \
     ${BOOST_VARIANT}                             \
     runtime-link=shared                          \
     link=shared                                  \
     --prefix=${INSTALL_ROOT}/usr                 \
     --toolset=gcc                                \
     threading=single,multi                       \
     --layout=system                              \
     $OPTS
