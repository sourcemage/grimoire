if [[ $BOINC_PARTS == client || $BOINC_PARTS == both ]]
then
  OPTS="$OPTS --enable-client"
fi &&
if [[ $BOINC_PARTS == server || $BOINC_PARTS == both ]]
then
  OPTS="$OPTS --enable-server"
fi &&
case "${SMGL_COMPAT_ARCH[0]}" in
  64)
    OPTS="$OPTS --enable-bitness=64"
    ;;
  32)
    OPTS="$OPTS --enable-bitness=32"
    ;;
esac &&
OPTS="$OPTS --with-gnu-ld --program-suffix=-cvs -C"
default_build
