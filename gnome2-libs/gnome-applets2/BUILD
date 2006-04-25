if [ "$KEYFLAGS" == "y" ]; then
   OPTS="$OPTS --enable-flags"
fi                                                               &&

if [ "$CPUFREQ" == "n" ]; then
   OPTS="$OPTS --disable-cpufreq"
fi                                                               &&

if [ "$FREQSEL" == "n" ]; then
   OPTS="$OPTS --enable-frequency-selector=no --enable-suid=no"
else
   if [ "$FREQSELSUID" == "n" ]; then
      OPTS="$OPTS --enable-suid=no"
   fi
fi                                                               &&

if [ "$IPV6" == "y" ]; then
   OPTS="$OPTS --enable-ipv6"
fi                                                               &&

make_single                                                      &&
default_build                                                    &&
make_normal
