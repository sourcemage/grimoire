if is_depends_enabled $SPELL ca-certificates; then
  local trust=(trust_paths="${INSTALL_ROOT}/etc/ssl/certs/ca-certificates.crt") &&
  OPTS="${trust[@]} $OPTS"
fi &&
meson_build
