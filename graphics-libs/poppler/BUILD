if [ "$A4PAPER" == "y" ]; then
   OPTS="$OPTS --enable-a4-paper"
fi                                 &&

if [ "$PSOPI" == "y" ]; then
   OPTS="$OPTS --enable-opi"
fi                                 &&
OPTS="--disable-utils --enable-xpdf-headers $OPTS"  &&
default_build
