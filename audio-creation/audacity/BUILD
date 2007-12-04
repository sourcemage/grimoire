if [ "$AUDACITY_UNI" == "y" ]; then
   OPTS="$OPTS --enable-unicode"
fi &&

if [ "$AUDACITY_REL" == "beta" ]; then
   OPTS="$AUDACITY_SOUNDTOUCH $OPTS"
fi &&

OPTS="$AUDACITY_LADSPA $AUDACITY_PORTMIXER $AUDACITY_PORTAUDIO $OPTS" &&

./configure  --prefix=${INSTALL_ROOT}/usr                \
             --sysconfdir=${INSTALL_ROOT}/etc            \
             --localstatedir=${INSTALL_ROOT}/var         \
             --mandir=${INSTALL_ROOT}/usr/share/man      \
             --infodir=${INSTALL_ROOT}/usr/share/info    \
             --with-lib-preference=system                \
             $OPTS                                       &&

make_single &&
make &&
make_normal
