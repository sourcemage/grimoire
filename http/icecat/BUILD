local ICECAT_HOME=${INSTALL_ROOT}/usr/lib/${SPELL}  &&
export  MOZ_PHOENIX=1                                  &&

export  CFLAGS="${CFLAGS//-O3/-O2}"      &&
export  CXXFLAGS="${CXXFLAGS//-O3/-O2}"  &&

OPTS="$ICECAT_MAILNEWS $ICECAT_CALENDAR $ICECAT_CHAT $ICECAT_COMPOSER  \
$ICECAT_MATHML $ICECAT_JS $OPTS"  &&

if [[ "$ICECAT_RENDER" != "none" ]]
then
  OPTS="--enable-svg-renderer=$ICECAT_RENDER $OPTS"
fi  &&

case $ICECAT_TOOLKIT in
  gtk2) OPTS="--enable-default-toolkit=cairo-gtk2" ;;
  qt-x11) OPTS="--enable-default-toolkit=cairo-qt" ;;
  *) message "unknown toolkit selected!" ; false ;;
esac

[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=$HOST"

./configure --prefix=${INSTALL_ROOT}/usr             \
        --sysconfdir=${INSTALL_ROOT}/etc             \
     --localstatedir=${INSTALL_ROOT}/var             \
            --mandir=${INSTALL_ROOT}/usr/share/man   \
           --infodir=${INSTALL_ROOT}/usr/share/info  \
  --with-user-appdir=.${SPELL}                       \
   --enable-optimize="$CFLAGS"                       \
     --with-pthreads                                 \
--enable-application=browser                         \
    --enable-reorder                                 \
   --enable-cpp-rtti                                 \
      --enable-strip                                 \
  --with-default-mozilla-five-home=$ICECAT_HOME      \
     --disable-debug                                 \
     --disable-tests                                 \
 --disable-installer                                 \
  --disable-pedantic                                 \
  --enable-single-profile                            \
 --enable-extensions="default"                       \
     --enable-canvas                                 \
               $OPTS                                           &&

make
