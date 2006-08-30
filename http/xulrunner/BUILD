MOZILLA_HOME=$INSTALL_ROOT/usr/lib/xulrunner    &&

#
# Only strip if the user wants us to
#
if  echo  $LDFLAGS  |  grep  -q  --  '-s';  then
  OPTS="$OPTS  --enable-strip"
fi  &&

if [[ $XULRUNNER_FONTS  ==  xft ]]
then
  OPTS="--enable-xft --disable-freetype2 $OPTS"
fi  &&
#
# No fast optimization for Mozilla, bit us so many times...
#
CFLAGS="${CFLAGS//-O3/-O2}"      &&
CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

./configure --prefix=$INSTALL_ROOT/usr                       \
            --mandir=$INSTALL_ROOT/usr/share/man             \
            --with-default-mozilla-five-home=$MOZILLA_HOME   \
            --with-user-appdir=.xulrunner                    \
            --enable-extensions=all${MOZILLA_EXT}            \
            --enable-optimize="$CFLAGS"                      \
            --with-pthreads                                  \
            --disable-freetype2                              \
            --enable-xft                                     \
            --disable-pango                                  \
            --enable-reorder                                 \
            --enable-elf-dynstr-gc                           \
            --enable-storage                                 \
            --enable-cpp-rtti                                \
            --enable-application=xulrunner                   \
            --disable-debug                                  \
            --disable-tests                                  \
            --disable-installer                              \
            --disable-updater                                \
            --disable-pedantic                               \
            --disable-composer                               \
            --disable-mailnews                               \
            --disable-calendar                               \
            $XULRUNNER_OPTS                                  \
            $OPTS                                            &&
make_single  &&

make
