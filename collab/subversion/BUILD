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

# AP{R,U} 0.9.12 patch, harmless for AP{R,U} 1
patch -p0 < $SCRIPT_DIRECTORY/apr-0.9.12.diff &&

OPTS="$OPTS --disable-debug --disable-static --disable-mod-activation --enable-dso --enable-shared --disable-neon-version-check" &&
make_single &&
default_build &&

if [[ "$SVN_PERL"   == y ]]; then make swig-pl; fi &&
if [[ "$SVN_PYTHON" == y ]]; then make swig-py; fi &&
if [[ "$SVN_RUBY"   == y ]]; then make swig-rb; fi &&

# Test if built from current source
if [[ "$SVN_HEAD" == y ]] && spell_ok python; then
  make check
fi
