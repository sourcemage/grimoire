OPTS="$ZNC_OPTS $OPTS" &&

if spell_ok libressl && ! is_version_less $(installed_version libressl) 3.4.0; then
  CXXFLAGS="-DHAVE_SSL_SESSION_get0_cipher ${CXXFLAGS}"
fi &&

default_build
