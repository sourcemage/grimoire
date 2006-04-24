#
#  Make EVDEV optional
#
if  [  "$LIBGII_EVDEV"  ==  "n"  ];  then
  OPTS="$OPTS  --disable-linux-evdev"
fi  &&

CFLAGS=${CFLAGS/-DPIC -fPIC/}  &&

default_build
