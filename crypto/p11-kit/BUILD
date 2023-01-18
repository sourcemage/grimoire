if [[ $OPTS = *trust_module=enabled* ]]; then
  TRUST=(trust_paths="${INSTALL_ROOT}/etc/ssl/certs/ca-certificates.crt") &&
  OPTS="${TRUST[@]} $OPTS"
fi &&
meson_build
