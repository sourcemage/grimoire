if [ "$AUDACITY_UNI" == "y" ]; then
   OPTS="$OPTS --enable-unicode"
fi &&

OPTS="$AUDACITY_SOUNDTOUCH $OPTS" &&
OPTS="$AUDACITY_LADSPA $OPTS"    &&
OPTS="$AUDACITY_PORTMIXER $OPTS" &&
OPTS="$AUDACITY_PORTAUDIO $OPTS" &&
OPTS="$AUDACITY_NYQUIST $OPTS"
OPTS="--with-lib-preferences=system $OPTS" &&

default_build
