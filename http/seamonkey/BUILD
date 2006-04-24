MOZILLA_HOME=$INSTALL_ROOT/usr/lib/seamonkey    &&

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

./configure --prefix=$INSTALL_ROOT/usr                       \
            --mandir=$INSTALL_ROOT/usr/share/man             \
            --with-default-mozilla-five-home=$MOZILLA_HOME   \
            --with-user-appdir=.seamonkey                    \
            --enable-extensions=all${MOZILLA_EXT}            \
            --enable-optimize="$CFLAGS"                      \
            --with-pthreads                                  \
            --disable-pango                                  \
            --disable-freetype2                              \
            --enable-canvas                                  \
            --enable-xft                                     \
            --enable-reorder                                 \
            --enable-elf-dynstr-gc                           \
            --enable-storage                                 \
            --enable-cpp-rtti                                \
            --enable-application=suite                       \
            --disable-debug                                  \
            --disable-tests                                  \
            --disable-installer                              \
            --disable-updater                                \
            --disable-pedantic                               \
            $SEAMONKEY_MAILNEWS                              \
            $SEAMONKEY_CHAT                                  \
            $SEAMONKEY_CALENDAR                              \
            $SEAMONKEY_COMPOSER                              \
            $SEAMONKEY_MATHML                                \
            $SEAMONKEY_JS                                    \
            $SEAMONKEY_XINERAMA                              \
            $OPTS                                            &&
make_single  &&
make
