unset LANG

if ! declare -f up_trigger > /dev/null; then
# save current version so we can do a TRIGGERS, only on sorcery < 1.13
#
persistent_add PREVIOUS_VERSION	&&
PREVIOUS_VERSION="`installed_version perl`"
fi  &&
CONFIG="$DEPENDS_CONFIG/perl_config.sh"     &&

SITEMAN1DIR="${INSTALL_ROOT}/usr/share/site_perl/man/man1"     &&
SITEMAN3DIR="${INSTALL_ROOT}/usr/share/site_perl/man/man3"     &&
VENDORMAN1DIR="${INSTALL_ROOT}/usr/share/vendor_perl/man/man1"     &&
VENDORMAN3DIR="${INSTALL_ROOT}/usr/share/vendor_perl/man/man3"     &&

PERL_PATHS="-Dprefix=/usr \
           -Dvendorprefix=/usr -Dvendorman1dir=$VENDORMAN1DIR -Dvendorman3dir=$VENDORMAN3DIR \
           -Dsiteprefix=/usr -Dsiteman1dir=$SITEMAN1DIR -Dsiteman3dir=$SITEMAN3DIR " &&

CONFIG_OPTS="-Ui_db -Duseshrplib -Ulocincpth=" &&

if glibc_is_nptl; then
  LDFLAGS="$LDFLAGS -lpthread"
fi &&

if [ "$OLD_CUSTOM" == "y" ]; then 
   CONFIG_OPTS="-S "
   cp $CONFIG ./config.sh
fi &&

[ "$THREADED" == "y" ] && CONFIG_OPTS="$CONFIG_OPTS -Dusethreads"
[ "$OLD_CUSTOM" != "y" ] && [ "NEW_CUSTOM" != "y" ] && CONFIG_OPTS="-d -e $CONFIG_OPTS"
./Configure -Doptimize="$CFLAGS" $CONFIG_OPTS $PERL_PATHS &&
if [ "$NEW_CUSTOM"  ==  "y" ]; then
   cp config.sh $CONFIG
fi &&
make depend &&
make
 
#if  [  "$OLD_CUSTOM"  ==  "y"  ];  then
#  cp $CONFIG ./config.sh  &&
#  ./Configure -S  -Dprefix=/usr -Dvendorprefix=/usr -Dvendorman1dir=$VENDORMAN1DIR  -Dvendorman3dir=$VENDORMAN3DIR   &&
#  make depend
#else
#  if  [  "$NEW_CUSTOM"  ==  "y"  ];  then
#    ./Configure -Ui_db -Dprefix=/usr -Dvendorprefix=/usr -Dvendorman1dir=$VENDORMAN1DIR  -Dvendorman3dir=$VENDORMAN3DIR \
#                -Dlibperl=libperl.so  &&
#    cp config.sh $CONFIG
#  else
#    if  [  "$THREADED"  ==  "y"  ];  then
#      ./Configure  -Dprefix=/usr -d -e                                   \
#                   -Ui_db -Dvendorprefix=/usr -Dvendorman1dir=$VENDORMAN1DIR  -Dvendorman3dir=$VENDORMAN3DIR -Dusethreads -Ulocincpth -Dlibperl=libperl.so
#    else
#      ./Configure  -Dprefix=/usr -d -e                      \
#                   -Ui_db -Dvendorprefix=/usr -Dvendorman1dir=$VENDORMAN1DIR  -Dvendorman3dir=$VENDORMAN3DIR -Ulocincpth -Dlibperl=libperl.so
#    fi
#  fi
#fi  &&
#make


