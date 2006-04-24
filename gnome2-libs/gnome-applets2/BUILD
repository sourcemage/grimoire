if [ "$KEYFLAGS" == "y" ]; then
   OPTS="$OPTS --enable-flags"
fi                                                               &&

if [ "$CPUFREQ" == "y" ]; then
   OPTS="$OPTS --enable-cpufreq"
else
   OPTS="$OPTS --disable-cpufreq"
fi                                                               &&

if [ "$FREQSEL" == "y" ]; then
   OPTS="$OPTS --enable-frequency-selector"                      &&
   if [ "$FREQSELSUID" == "y" ]; then
      OPTS="$OPTS --enable-suid"
   else
      OPTS="$OPTS --disable-suid"
   fi
else
   OPTS="$OPTS --disable-frequency-selector --disable-suid"
fi                                                               &&

if [ "$IPV6" == "y" ]; then
   OPTS="$OPTS --enable-ipv6"
fi                                                               &&

make_single                                                      &&
default_build                                                    &&
make_normal
