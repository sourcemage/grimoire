#
# Fix compilation with GCC 4.4
#
CXXFLAGS="-Wno-strict-aliasing $CXXFLAGS" &&

local BOOST_LIBS="${BOOST_LIBS_AL} ${BOOST_LIBS_MZ}" &&
local BLIST=""                                    &&
local BL                                          &&
if [[ $BOOST_SELECT_LIBS == "n" ]]; then
  BLIST=""
else
  local SEP=" --with-"                            &&
  for BL in $BOOST_LIBS $BOOST_OPTS1 ; do
    BL=${BL// /}                                  &&
    BLIST="${BLIST}${SEP}${BL}"
  done
fi                                                &&
if list_find "${BOOST_LIBS}" "graph"           ||
   [[ $BOOST_SELECT_LIBS == "n" ]]; then
   local EXPAT_INCLUDE=/usr/lib
   local EXPAT_LIBPATH=/usr/include
fi &&
./bootstrap.sh --with-toolset=gcc                 \
     -prefix=${INSTALL_ROOT}/usr                  \
     --with-libraries=${BOOST_LIBS}               &&
OPTS="$OPTS $BLIST"                               &&
CXXFLAGS="$CXXFLAGS"                              \
EXPAT_INCLUDE=$EXPAT_INCLUDE                      \
EXPAT_LIBPATH=$EXPAT_LIBPATH                      \
./bjam -q                                           \
     ${BOOST_VARIANT}                             \
     runtime-link=shared                          \
     link=shared                                  \
     --prefix=${INSTALL_ROOT}/usr                 \
     --toolset=gcc                                \
     threading=multi                              \
     --layout=system                              \
     $OPTS
