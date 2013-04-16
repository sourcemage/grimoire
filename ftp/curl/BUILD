if [[ "$CURL_SSL" == "none" ]]; then
   OPTS="--without-gnutls --without-nss --without-ssl $OPTS"
fi &&

if echo "$CFLAGS" | grep -q -- '-DPIC'; then
  CFLAGS="${CFLAGS/-DPIC/}" &&
  CPPFLAGS="$CPPFLAGS -DPIC "
fi  &&

default_build
