export  XERCESCROOT=$SOURCE_DIRECTORY

if  echo $OPTS | grep -q 'ticu'; then
   export  ICUROOT=/usr
fi               &&

cd  src/xercesc  &&
autoconf         &&
  
chmod u+x runConfigure configure install-sh
./runConfigure  -plinux -cgcc -xg++ -minmem  \
        -nsocket -rpthread                   \
        $OPTS                                \
        -P /usr                              &&
  
make_single  &&
make
