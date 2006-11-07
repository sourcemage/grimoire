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
if spell_ok python; then
  PY_VER="`installed_version python|cut -c-3`"    &&
  persistent_add PY_VER
fi &&
CXXFLAGS="$CXXFLAGS"                              \
PYTHON_VERSION="$PY_VER"                          \
bjam --prefix=${INSTALL_ROOT}/usr                 \
     -sTOOLS=gcc                                  \
     "-sBUILD=${BOOST_VARIANT## }"                \
     --layout=system                              \
     $OPTS
