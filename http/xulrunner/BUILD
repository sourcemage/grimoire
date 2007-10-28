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

if [[ ${SMGL_COMPAT_ARCHS[1]} == ia32 ]]
then
  OPTS="--enable-elf-dynstr-gc $OPTS"
fi &&

./configure --prefix=$INSTALL_ROOT/usr                       \
            --mandir=$INSTALL_ROOT/usr/share/man             \
            --with-default-mozilla-five-home=$MOZILLA_HOME   \
            --with-user-appdir=.xulrunner                    \
            --enable-extensions=default,permissions,cookie,wallet   \
            --enable-optimize="$CFLAGS"                      \
            --with-pthreads                                  \
            --disable-freetype2                              \
            --enable-xft                                     \
            --disable-pango                                  \
            --enable-reorder                                 \
            --enable-storage                                 \
            --enable-cpp-rtti                                \
            --enable-application=xulrunner                   \
            --enable-cookies                                 \
            --disable-javaxpcom                              \
            --disable-composer                               \
            --disable-mailnews                               \
            --disable-calendar                               \
            --disable-debug                                  \
            --disable-tests                                  \
            --disable-installer                              \
            --disable-updater                                \
            --disable-pedantic                               \
            $XULRUNNER_OPTS                                  \
            $OPTS                                            &&

make_single  &&

make
