 local ICEWEASEL_HOME=${INSTALL_ROOT}/usr/lib/${SPELL}  &&
export  MOZ_PHOENIX=1                                  &&

export  CFLAGS="${CFLAGS//-O3/-O2}"      &&
export  CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

OPTS="$ICEWEASEL_MAILNEWS $ICEWEASEL_CALENDAR $ICEWEASEL_CHAT $ICEWEASEL_COMPOSER  \
$ICEWEASEL_MATHML $ICEWEASEL_JS $OPTS"  &&

if [[ "$ICEWEASEL_RENDER" != "none" ]]
then
  OPTS="--enable-svg-renderer=$ICEWEASEL_RENDER $OPTS"
fi  &&

./configure                                       \
  --prefix=${INSTALL_ROOT}/usr                    \
  --with-user-appdir=.${SPELL}                    \
  --with-pthreads                                 \
  --enable-application=browser                    \
  --enable-reorder                                \
  --enable-cpp-rtti                               \
  --enable-strip                                  \
  --enable-optimize="$CFLAGS"                     \
  --with-default-mozilla-five-home=$ICEWEASEL_HOME  \
  --disable-debug                                 \
  --disable-tests                                 \
  --disable-installer                             \
  --disable-pedantic                              \
  --enable-single-profile                         \
  --enable-extensions=default,typeaheadfind       \
  --enable-canvas                                 \
  $OPTS                                           &&

make
