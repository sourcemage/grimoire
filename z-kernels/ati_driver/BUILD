cd $SOURCE_DIRECTORY                 &&
cd lib/modules/fglrx/build_mod       &&
local ATI_KERNEL_VERSION=`uname -r`  &&
if [ "${ATI_KERNEL_VERSION:0:6}" == "2.6.11" ]; then
  patch -p1 <$SCRIPT_DIRECTORY/8.10.19-2.6.11.patch
fi  &&
sh ./make.sh  &&
if [ "${ATI_DRIVER_QT}" == "y" ]; then
  cd $SOURCE_DIRECTORY/fglpanel                  &&
  patch -p0 < ${SCRIPT_DIRECTORY}/smgl.qt.patch  &&
  make
fi
