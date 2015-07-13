# It uses -Werror, so we must avoid warnings
for flag in \
  -Wunsafe-loop-optimizations
do
  CFLAGS="${CFLAGS/$flag}"
done &&
CFLAGS="$CFLAGS -D_DEFAULT_SOURCE" &&
default_build
