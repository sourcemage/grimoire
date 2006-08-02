FIREFOX_HOME=${INSTALL_ROOT}/usr/lib/firefox                &&
export  MOZ_PHOENIX=1                                       &&

# No fast optimization for Mozilla, bit us so many times...
export  CFLAGS="${CFLAGS//-O3/-O2}"      &&
export  CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

# these two are simply bugs in the Makefile-s
sedit 's#-lgfxshared_s#-L../shared -lgfxshared_s#g' gfx/src/gtk/Makefile.in &&
sedit 's#-lxprintutil#-L../xprintutil -lxprintutil#g' gfx/src/gtk/Makefile.in &&

mozilla_remove_nspr_nss &&

if  [  -f  /root/.mozconfig  ];  then
  rm  -f  /root/.mozconfig
fi  &&

if [ "$FIREFOX_CVS" == "y" ]; then
  OPTS="$OPTS --enable-application=browser"
fi &&
cp browser/config/mozconfig .mozconfig &&

# Ugly hack to get spells using gecko engine to compile against the headers and libs
# under /usr/lib/firefox instead of /usr/lib.firefox-$VERSION, so that we can avoid
# to recompile them on each minor upgrade
# This will make the replacement in pkconfig files and firefox-config command
sedit 's#$(includedir)#/usr/include/firefox#g' build/unix/Makefile.in  &&
sedit 's#$(mozappdir)#/usr/lib/firefox#g' build/unix/Makefile.in  &&
sedit 's#$(idldir)#/usr/share/idl/firefox#g' build/unix/Makefile.in  &&

./configure                                       \
  --prefix=${INSTALL_ROOT}/usr                    \
  --with-user-appdir=.firefox                     \
  --with-x                                        \
  --with-pthreads                                 \
  --enable-reorder                                \
  --enable-cpp-rtti                               \
  --enable-strip                                  \
  --enable-optimize="$CFLAGS"                     \
  --with-default-mozilla-five-home=$FIREFOX_HOME  \
  --disable-debug                                 \
  --disable-tests                                 \
  --disable-installer                             \
  --disable-pedantic                              \
  --disable-mailnews                              \
  --disable-composer                              \
  --enable-single-profile                         \
  --enable-extensions=default,typeaheadfind       \
  --enable-canvas                                 \
  $OPTS                                           &&

make_single                                       &&
make                                              &&

# fix pkgconfig files so that other spell using them can build properly
# these files will be renamed to firefox-{nspr,nss}.pc during installation
cp -f $GRIMOIRE/libs/nspr/mozilla-nspr.pc build/unix/firefox-nspr.pc &&
cp -f $GRIMOIRE/crypto/nss/mozilla-nss.pc build/unix/firefox-nss.pc  &&
sedit 's|Requires:\s*firefox-nspr.*$|Requires: mozilla-nspr|g' build/unix/firefox-xpcom.pc
