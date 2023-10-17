# FIXME Engine API is only partially implemented on LibreSSL 3.8.1
if is_depends_enabled "$SPELL" libressl; then
  OPTS+=" --without-openssl-engine"
fi &&
default_build
