if [ "$AUDACITY_UNI" == "y" ]; then
   OPTS="$OPTS --enable-unicode"
fi &&

if [ "$AUDACITY_REL" == "beta" ]; then
   OPTS="$AUDACITY_SOUNDTOUCH $OPTS"
fi &&

OPTS="$AUDACITY_LADSPA $AUDACITY_PORTMIXER $AUDACITY_PORTAUDIO $OPTS" &&

./configure  --prefix=/usr                \
             --sysconfdir=/etc            \
             --localstatedir=/var         \
             --with-lib-preference=system \
             $OPTS                        &&

make_single &&
make &&
make_normal
