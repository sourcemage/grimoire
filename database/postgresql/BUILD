create_account postgres &&

OPTS="--with-docdir=$INSTALL_ROOT/usr/share/doc $OPTS"

default_build &&

if is_depends_enabled $SPELL openssl; then
  cd contrib/pgcrypto &&
  make
fi &&

if is_depends_enabled $SPELL libxml2; then
  cd ../xml2 &&
  make
fi
