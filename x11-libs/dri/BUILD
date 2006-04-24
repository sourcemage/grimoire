cd    $SOURCE_DIRECTORY/xc-Trunk/                 &&
make  World  PROJECTROOT=$INSTALL_ROOT/usr/X11R6  &&

cd    $SOURCE_DIRECTORY/Mesa-Trunk/ &&
if [ "`find ${ARCH_SPECS} -type f -name ${ARCHITECTURE} | awk -F/ '{print$6;}'`" == "ia32" ]
then
   make linux-dri-x86
elif [ "`find ${ARCH_SPECS}  -type f -name ${ARCHITECTURE} | awk -F/ '{print$6;}'`" == "ppc" ]
then
   make linux-dri-ppc
elif [ "`find ${ARCH_SPECS} -type f -name ${ARCHITECTURE} | awk -F/ '{print$6;}'`" == "amd64" ]
then
   make linux-dri-x86_64
else
   make linux-dri
fi &&


if [ "`uname -r | cut -c-3`" == "2.6" ]; then
  cd  $SOURCE_DIRECTORY/drm-Trunk/linux-core
else
  cd $SOURCE_DIRECTORY/drm-Trunk/linux
fi  &&

make
