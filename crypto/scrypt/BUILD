# Avoid configure test that depends on getconf
OPTS+=" POSIX_SH=$INSTALL_ROOT/bin/sh" &&
OPTS="${SCRYPT_OPTS} ${OPTS}" &&

if is_depends_enabled ${SPELL} meson; then
  source "${GRIMOIRE}/MESON_FUNCTIONS"
fi &&

default_build
