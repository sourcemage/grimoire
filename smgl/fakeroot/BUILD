case "$HOST" in *-musl)
  CFLAGS+=" -D_STAT_VER=0" ;;
esac &&
if spell_ok glibc && installed_version glibc >= 2.33;then
  CFLAGS+=" -D_STAT_VER=0"
fi &&
default_build
