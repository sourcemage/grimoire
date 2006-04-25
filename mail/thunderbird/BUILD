THUNDERBIRD_HOME=${INSTALL_ROOT}/usr/lib/thunderbird &&
export  MOZILLA_OFFICIAL="1"  &&
export  BUILD_OFFICIAL="1"    &&
export  MOZ_THUNDERBIRD="1"   &&

#
# No fast optimization for Mozilla, bit us so many times...
#
export  CFLAGS="${CFLAGS//-O3/-O2}"      &&
export  CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

# these two are simply bugs in the Makefile-s
sedit 's#-lgfxshared_s#-L../shared -lgfxshared_s#g' gfx/src/gtk/Makefile.in &&
sedit 's#-lxprintutil#-L../xprintutil -lxprintutil#g' gfx/src/gtk/Makefile.in &&

if  [[  "$THUNDERBIRD_MATHML"  ==  'y'  ]];  then
  OPTS="$OPTS  --enable-mathml"
else
  OPTS="$OPTS  --disable-mathml"
fi &&

if  echo $LDFLAGS | grep  -q  '\-s'; then
  OPTS="$OPTS  --enable-strip"
fi  &&

# Note: --enable-extensions and --enable-necko-protocols are inherited from
# mozconfig.  Don't set them in ./configure unless you *really* know what
# you're doing.
# Also already in mozconfig:
#            export MOZ_THUNDERBIRD=1
#            mk_add_options MOZ_THUNDERBIRD=1
#
#            --enable-crypto                              \
#            --enable-single-profile                      \
#            --disable-tests                              \
#            --disable-oji                                \
#            --disable-necko-disk-cache                   \
#            --disable-profilesharing                     \
#            --disable-activex                            \
#            --disable-activex-scripting                  \
#            --disable-plugins                            \
#            --enable-image-decoders=default,-xbm         \

./configure --prefix=${INSTALL_ROOT}/usr \
            --with-user-appdir=.thunderbird              \
            --with-default-mozilla-five-home=$THUNDERBIRD_HOME \
            --enable-application=mail \
            --enable-extensions=wallet,spellcheck,xmlextras,webservices \
            --enable-crypto \
            --enable-xinerama \
            --enable-optimize \
            --enable-reorder \
            --enable-strip \
            --enable-cpp-rtti \
            --enable-single-profile \
            --enable-necko-protocols=http,file,jar,viewsource,res,data \
            --enable-image-decoders=default,-xbm \
            --disable-accessibility \
            --disable-debug \
            --disable-ldap  \
            --disable-tests \
            --disable-logging \
            --disable-pedantic \
            --disable-installer \
            --disable-profilesharing \
            --disable-oji \
            --disable-plugins \
            --disable-necko-disk-cache \
              $OPTS                                        &&

make &&

if [[ "$BUILD_ENIGMAIL" == 'y' ]]; then
   build/autoconf/make-makefile extensions/ipc extensions/enigmail &&
   make -C extensions/ipc &&
   make -C extensions/enigmail
fi
