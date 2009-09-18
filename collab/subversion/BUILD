# -ggdb conflicts with --disable-debug OPT
  CFLAGS=${CFLAGS/-ggdb/}
CPPFLAGS=${CPPFLAGS/-ggdb/}
CXXFLAGS=${CXXFLAGS/-ggdb/}
# only check for Apache if the modules are needed
if echo $OPTS | grep -q 'with-apxs'; then
  message "${MESSAGE_COLOR}Checking for Apache 2.x${DEFAULT_COLOR}" &&
  $INSTALL_ROOT/usr/sbin/httpd -v | grep -q 'Apache/2\.'            &&

  # check if mod_dav is present; it can be dynamic or static, we check both
  message "${MESSAGE_COLOR}Checking for mod_dav.so Apache module${DEFAULT_COLOR}" &&
  if   ! [ -e $INSTALL_ROOT/usr/libexec/mod_dav.so ] \
    && ! $INSTALL_ROOT/usr/sbin/httpd -l | grep -q 'mod_dav\.c'
  then
    message "${MESSAGE_COLOR}Module mod_dav not found!${DEFAULT_COLOR}" &&
    message "${MESSAGE_COLOR}Please recompile Apache 2 with mod_dav support.${DEFAULT_COLOR}" &&
    false
  fi
fi &&

if ! [[ -x configure ]]; then ./autogen.sh; fi &&

if [[ "$(get_spell_provider $SPELL APR)" == "apr" ]] || \
   [[ "$(get_spell_provider $SPELL APU)" == "apr-util" ]]; then
  CFLAGS="${CFLAGS} $(/usr/bin/apr-1-config --cppflags)" &&
  OPTS="${OPTS} --disable-debug --disable-static --disable-mod-activation --enable-shared --disable-experimental-libtool"
else
  OPTS="${OPTS} --disable-debug --disable-static --disable-mod-activation --enable-shared --disable-neon-version-check"
fi &&

SWIG_LDFLAGS="${LDFLAGS}" &&
make_single &&
OPTS="--enable-runtime-module-search $OPTS" default_build &&

if [[ "$SVN_PERL"   == y ]]; then
  mkdir -p subversion/bindings/swig/perl/native/blib/arch/auto/SVN/{_Client,_Delta,_Fs,_Ra,_Repos,_Wc} &&
  make swig-pl
fi &&
if [[ "$SVN_PYTHON" == y ]]; then make swig-py; fi &&
if [[ "$SVN_RUBY"   == y ]]; then make swig-rb; fi &&

# Test if built from current source
if [[ "$SVN_HEAD" == y ]] && spell_ok python; then
  make check
fi
