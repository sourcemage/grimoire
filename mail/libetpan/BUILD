if [[ "$LIBETPAN_TLS" == "none" ]]
then
  OPTS="--without-gnutls --without-openssl $OPTS"
fi   &&
cd "$SOURCE_DIRECTORY" &&
touch README INSTALL COPYING &&
autoreconf -i -s &&
default_build
