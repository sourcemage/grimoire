export CFLAGS+=' -fPIC' 
export LDFLAGS+=' -L/lib64 -lm'
unset LANG

if ! declare -f up_trigger > /dev/null; then
# save current version so we can do a TRIGGERS, only on sorcery < 1.13
#
persistent_add PREVIOUS_VERSION	&&
PREVIOUS_VERSION="`installed_version perl`"
fi &&
local PERL_CONFIG="$DEPENDS_CONFIG/perl_config.sh" &&

SITEMAN1DIR="${INSTALL_ROOT}/usr/share/site_perl/man/man1" &&
SITEMAN3DIR="${INSTALL_ROOT}/usr/share/site_perl/man/man3" &&
VENDORMAN1DIR="${INSTALL_ROOT}/usr/share/vendor_perl/man/man1" &&
VENDORMAN3DIR="${INSTALL_ROOT}/usr/share/vendor_perl/man/man3" &&

PERL_PATHS="-Dprefix=/usr \
           -Dvendorprefix=/usr -Dvendorman1dir=$VENDORMAN1DIR -Dvendorman3dir=$VENDORMAN3DIR \
           -Dsiteprefix=/usr -Dsiteman1dir=$SITEMAN1DIR -Dsiteman3dir=$SITEMAN3DIR " &&

local CONFIG_OPTS="-Ui_db -Duseshrplib -Ulocincpth=" &&

if glibc_is_nptl; then
  LDFLAGS="$LDFLAGS -lpthread"
fi &&

if [[ $OLD_CUSTOM == y ]]; then 
   CONFIG_OPTS="-S "
   cp $PERL_CONFIG ./config.sh
fi &&

if [[ $THREADED == y ]]; then
  CONFIG_OPTS="$CONFIG_OPTS -Dusethreads"
fi  &&

if [[ $NEW_CUSTOM != y ]]; then
  CONFIG_OPTS="-d -e $CONFIG_OPTS"
else
   rm -f config.sh
fi  &&

if ! is_depends_enabled $SPELL libxcrypt; then
  sed -i -e '/<<EOT >>config\.sh/,/^EOT/ {
             s/^cryptlib=.*/cryptlib='"''"'/
             s/^d_crypt=.*/d_crypt='"'undef'"'/
             s/^d_crypt_r=.*/d_crypt_r='"'undef'"'/
             s/^i_crypt=.*/i_crypt='"'undef'"'/
             }
             \#^\. \./UU/extract#i cryptlib='"''"'\
             perllibs=${perllibs//-lcrypt}
             ' Configure
fi &&

BUILD_ZLIB=False BUILD_BZIP2=0 \
setarch ${HOST%%-*} ./Configure -Doptimize="$CFLAGS" $CONFIG_OPTS $PERL_PATHS &&

make depend  &&
make         &&

if [[ $NEW_CUSTOM  ==  y ]]; then
   cp config.sh $PERL_CONFIG
fi
