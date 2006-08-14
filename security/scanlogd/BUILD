create_account  scanlogd

sedit  "s:/usr/local/:/usr/:"               Makefile  &&
sedit  "s:\-O2:$CFLAGS:"                    Makefile  &&
sedit  "s:/usr/include/pcap:/usr/include:"  Makefile  &&

if  list_find  "$OPTS"  '--enable-libpcap';  then
  echo "Building libpcap..."
  make  libpcap
elif  [[ "$SCANLOGD_LIBNIDS"  ==  "y" ]];  then
  echo "Building libnids..."
  make  libnids
else
  echo "Building linux..."
  make  linux
fi
