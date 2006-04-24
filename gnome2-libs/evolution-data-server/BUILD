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

make_single    &&
default_build  &&
make_normal
