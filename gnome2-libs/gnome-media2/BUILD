OPTS="$OPTS $GMEDIA_IPV6 $GMEDIA_GSR"  &&

if [[ $GMEDIA_GMP == y ]]; then
  OPTS="$OPTS --enable-profiles"
else
  OPTS="$OPTS --disable-profiles"
fi  &&

OPTS="$OPTS $GMEDIA_GSTPROPS $GMEDIA_GSTMIXR "  &&

default_build
