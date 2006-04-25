SUNBIRD_HOME=${INSTALL_ROOT}/usr/lib/sunbird &&
export  MOZILLA_OFFICIAL="1"  &&
export  BUILD_OFFICIAL="1"    &&
export  MOZ_SUNBIRD="1"       &&

#
# No fast optimization for Mozilla, bit us so many times...
#
export  CFLAGS="${CFLAGS//-O3/-O2}"      &&
export  CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

# these two are simply bugs in the Makefile-s
sedit 's#-lgfxshared_s#-L../shared -lgfxshared_s#g' gfx/src/gtk/Makefile.in &&
sedit 's#-lxprintutil#-L../xprintutil -lxprintutil#g' gfx/src/gtk/Makefile.in &&

if  grep  -q  "\-s"  ${LDFLAGS}
then
  OPTS="${OPTS}  --enable-strip"
fi  &&

mozilla_remove_nspr_nss &&

cp calendar/sunbird/config/mozconfig .mozconfig  &&

./configure --prefix=${INSTALL_ROOT}/usr \
            --with-user-appdir=.sunbird              \
            --with-default-mozilla-five-home=$SUNBIRD_HOME \
            --enable-calendar  \
            --enable-xinerama \
            --enable-optimize \
            --enable-reorder \
            --enable-strip \
            --enable-cpp-rtti \
            --enable-single-profile \
            --disable-mailnews \
            --disable-composer \
            --disable-freetype2  \
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

make
