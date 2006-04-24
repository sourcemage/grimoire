  patch -p0 <$SPELL_DIRECTORY/mk.patch &&
  autoheader &&
  autoconf   &&
  OPTS="--sysconfdir=${INSTALL_ROOT}/etc/privoxy -with-user=nobody --with-group=nogroup ${OPTS}" &&
  default_build
