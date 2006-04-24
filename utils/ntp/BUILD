create_account  ntp  &&

for i in $(grep -rl CONFIG_PHONE .);  do
  sedit  "s/CONFIG_PHONE/NTP_CONFIG_PHONE/g"  $i
done  &&

OPTS="$OPTS --enable-linuxcaps" &&
default_build
