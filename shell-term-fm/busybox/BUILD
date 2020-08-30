CFLAGS="${CFLAGS} -isystem /usr/include/tirpc" &&
# Some library linking needs to be enforced (static build, as-needed, maybe).
extralibs="pthread tirpc" &&
if is_depends_enabled "$SPELL" linux-pam; then
  extralibs+=" pam"
fi &&
make CONFIG_EXTRA_LDLIBS="$extralibs"
