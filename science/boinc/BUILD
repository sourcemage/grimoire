#disabling the server intentionally, because it doesn't build
#I left the logic in case someone can get the server to build
BOINC_PARTS='client' &&

if [[ "x${BOINC_PARTS}" == 'xclient' ]]; then
  OPTS="$OPTS --disable-server"
elif [[ "x${BOINC_PARTS}" == 'xserver' ]]; then
  OPTS="$OPTS --disable-client"
fi &&

case "${SMGL_COMPAT_ARCH[0]}" in
  64)
    OPTS="$OPTS --enable-bitness=64"
    ;;
  32)
    OPTS="$OPTS --enable-bitness=32"
    ;;
esac &&

OPTS="$OPTS --with-gnu-ld -C --enable-unicode"  &&

default_build
