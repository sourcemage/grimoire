create_account postgres &&

OPTS="--with-system-tzdata=$INSTALL_ROOT/usr/share/zoneinfo $OPTS"  &&
CFLAGS="${CFLAGS//-ffast-math}" &&

default_build &&

if is_depends_enabled $SPELL openssl; then
  cd contrib/pgcrypto &&
  make &&
  cd $SOURCE_DIRECTORY
fi &&

if is_depends_enabled $SPELL libxml2; then
  cd contrib/xml2 &&
  make &&
  cd $SOURCE_DIRECTORY
fi
