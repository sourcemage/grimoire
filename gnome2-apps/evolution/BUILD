if [ "$IPV6" == "y" ] ; then
   OPTS="$OPTS --enable-ipv6=yes"
else
   OPTS="$OPTS --enable-ipv6=no"
fi &&

if [ "$NNTP" == "y" ] ; then
   OPTS="$OPTS --enable-nntp=yes"
else
   OPTS="$OPTS --enable-nntp=no"
fi &&

if [ "$PLUGINS" == "y" ] ; then
   OPTS="$OPTS --enable-plugins=all"
else
   OPTS="$OPTS --enable-plugins=no"
fi &&

default_build

