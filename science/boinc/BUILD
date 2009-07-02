#disabling the server intentionally, because it doesn't build
#I left the logic in case someone can get the server to build
BOINC_PARTS="client" &&
if [[ $BOINC_PARTS == client ]]
then
  OPTS="$OPTS --disable-server"
fi &&
if [[ $BOINC_PARTS == server ]]
then
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

OPTS="$OPTS --with-gnu-ld --program-suffix=-svn -C --enable-unicode"

default_build
