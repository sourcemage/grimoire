if [ "$AUDACITY_UNI" == "y" ]; then
   OPTS="$OPTS --enable-unicode"
fi &&

OPTS="$AUDACITY_LADSPA $OPTS"    &&
OPTS="$AUDACITY_PORTMIXER $OPTS" &&
OPTS="$AUDACITY_NYQUIST $OPTS"   &&
# Things are too fragile for that.
#OPTS="--with-lib-preferences=system $OPTS" &&

default_build
