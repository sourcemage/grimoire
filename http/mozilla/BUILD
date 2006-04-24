MOZILLA_HOME=$INSTALL_ROOT/usr/lib/mozilla    &&

if  [[  "$MOZILLA_ENIGMAIL"  ==  'y'  ]];  then
  MOZILLA_EXT="$MOZILLA_EXT,ipc,enigmail"
fi  &&

if  [[  "$MOZILLA_RENDER"  ==  'libart_svg'  ]];  then
  export MOZ_INTERNAL_LIBART_LGPL=1   &&
  OPTS="--enable-svg-renderer-libart  \
        $OPTS"
elif [[  "$MOZILLA_RENDER"  ==  'cairo'  ]];  then
  OPTS="--enable-svg-renderer-cairo  \
        $OPTS"
fi  &&

#
# Only strip if the user wants us to
#
if  echo  $LDFLAGS  |  grep  -q  --  '-s';  then
  OPTS="$OPTS  --enable-strip"
fi  &&

#
# No fast optimization for Mozilla, bit us so many times...
#
CFLAGS="${CFLAGS//-O3/-O2}"      &&
CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

# these two are simply bugs in the Makefile-s
sedit 's#-lgfxshared_s#-L../shared -lgfxshared_s#g' gfx/src/gtk/Makefile.in &&
sedit 's#-lxprintutil#-L../xprintutil -lxprintutil#g' gfx/src/gtk/Makefile.in &&

mozilla_remove_nspr_nss &&

# fixup the pkgconfig files to use the system nspr/nss ones too
patch  -p0  <  $SCRIPT_DIRECTORY/pkgconfig.patch  &&

./configure               --prefix=$INSTALL_ROOT/usr            \
                          --mandir=$INSTALL_ROOT/usr/share/man  \
  --with-default-mozilla-five-home=$MOZILLA_HOME                \
               --enable-extensions=all${MOZILLA_EXT}            \
                 --enable-optimize="$CFLAGS"                    \
                            --with-pthreads                     \
                          --enable-xft                          \
                          --enable-reorder                      \
                          --enable-cpp-rtti                     \
                         --disable-debug                        \
                         --disable-tests                        \
                         --disable-installer                    \
                         --disable-ldap                         \
                         --disable-pedantic                     \
                                   $MOZILLA_MAILNEWS            \
                                   $MOZILLA_CHAT                \
                                   $MOZILLA_CALENDAR            \
                                   $MOZILLA_COMPOSER            \
                                   $MOZILLA_MATHML              \
                                   $MOZILLA_JS                  \
                                   $MOZILLA_XINERAMA            \
                                   $OPTS                        &&

make_single  &&

if  [[  "$MOZILLA_ENIGMAIL"  ==  'y'  ]];  then
  #
  # fix a problem of enigmail not compiling
  # because S/MIME IDL files are not exported in advance
  #
  if  !  make export;  then
    pushd  mailnews/extensions/smime/public  &&
    make  export                             &&
    popd                                     &&
    make  export
  fi
fi  &&

# the NSPR_CONFIG=... is needed so mozilla-config gets generated correctly,
# probably a bug in configure, but that's the easiest fix I found
make  NSPR_CONFIG=$INSTALL_ROOT/usr/bin/nspr-config
