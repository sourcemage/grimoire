if [ "$REL" == "beta" ]; then
   OPTS="$SOUNDTOUCH $OPTS"
fi &&

OPTS="$LADSPA $PORTMIXER $PORTAUDIO $OPTS" &&

./configure  --prefix=/usr         \
             --sysconfdir=/etc     \
             --localstatedir=/var  \
             $OPTS                 &&

make_single &&
make &&
make_normal
