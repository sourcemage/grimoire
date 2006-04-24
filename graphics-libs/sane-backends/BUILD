if [ "$USEFORK" == "y" ]; then
   OPTS="$OPTS --enable-fork-process"
else
   OPTS="$OPTS --disable-fork-process"
fi &&

if [ "$IPV6" == "y" ]; then
   OPTS="$OPTS --enable-ipv6"
else
   OPTS="$OPTS --disable-ipv6"
fi &&

default_build
