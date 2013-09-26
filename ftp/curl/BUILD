if [[ "$CURL_SSL" == "none" ]]; then
   OPTS="--without-gnutls --without-nss --without-ssl $OPTS"
fi &&

if [[ "$CFLAGS" != "${CFLAGS//-DPIC/}" ]]; then
  CFLAGS="${CFLAGS//-DPIC/}" &&
  CPPFLAGS="$CPPFLAGS -DPIC "
fi  &&

default_build
