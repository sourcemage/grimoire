# again check if it's there or net and only then use the variable
# else one would lose sse support on a new system
if ! grep -q "sse" /proc/cpuinfo ; then
  if [[ $OPENSSL_SSE == n ]]; then
    OPTS="no-sse2 $OPTS"
  fi
fi                                                          &&
OPTS="$OPENSSL_TLSEXT $OPTS"                                &&
OPTS="--prefix=${INSTALL_ROOT}/usr                          \
      --openssldir=${INSTALL_ROOT}/etc/ssl                  \
      --libdir=lib                                          \
      enable-md2                                            \
      shared                                                \
      threads                                               \
      $OPTS" &&
setarch ${HOST%%-*} ./config  $OPTS   &&

sedit  "s/-O3//"                    Makefile                &&
sedit  "s/-m486//"                  Makefile                &&
if [[ ${SMGL_COMPAT_ARCHS[1]} != alpha ]] && [[ $CFLAGS == ${CFLAGS/-O/} ]]; then
  CFLAGS="$CFLAGS -O"; # bug 13855, but not for alpha
fi &&
sedit  "s/^CFLAG=/CFLAG=$CFLAGS /"  Makefile                &&
sedit  "s/chmod 644\(.*pkgconfig\)/chmod 755\1/"  Makefile  &&

make                &&
make build_man_docs &&
{

  local OLD_SPELL_VERSION=""
  spell_ok $SPELL && OLD_SPELL_VERSION="$(installed_version $SPELL)"
  if [ "${VERSION/[a-z]*/}" != "${OLD_SPELL_VERSION/[a-z]*/}" ] &&
       grep -q '^wget:openssl:on' "$DEPENDS_STATUS" # any internal sorcery interface to this data?
    then
    message "Building wget now so that it doesn't get borked" &&
    summon wget                               &&
    RUN_COMPILER_DIR="${RUN_COMPILER_DIR:-/var/lib/sorcery/build}" &&
    PATH="${PATH//$RUN_COMPILER_DIR:/}"                            &&
    (
    # Build wget with just prepared openssl.
    OPTS="--with-ssl=openssl" \
    OPENSSL_CFLAGS="-I$SOURCE_DIRECTORY/include" \
    OPENSSL_LIBS="-L$SOURCE_DIRECTORY $(PKG_CONFIG_LIBDIR=$SOURCE_DIRECTORY pkg-config --libs openssl)" \
    delve -c start BUILD wget &&
    local TEMPWGET_DIR="$BUILD_DIRECTORY/wget-$(gaze version wget |
                        head -n 3 | tail -n 1 | awk '{ print $4 }')" &&
                        # $4 is grimoire version, not installed version -- internal sorcery interface, too?
    cp "$TEMPWGET_DIR/src/wget" "$SOURCE_DIRECTORY"
    )
  fi
}
