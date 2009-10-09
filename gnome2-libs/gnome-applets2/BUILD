if [ "$KEYFLAGS" == "y" ]; then
   OPTS="$OPTS --enable-flags"
fi                                                               &&

if [ "$FREQSELSUID" == "n" ]; then
   OPTS="$OPTS --enable-suid=no"
fi                                                               &&

if [ "$IPV6" == "y" ]; then
   OPTS="$OPTS --enable-ipv6"
fi                                                               &&

make_single                                                      &&
default_build                                                    &&
make_normal
