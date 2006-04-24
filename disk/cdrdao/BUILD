##### Patch needed for building on x86_64 ######
ARCH=$(uname -m)                                                        &&
if [ "${ARCH:0:6}" = "x86_64" ]; then 
    cd scsilib/RULES                                                    && 
    cp i686-linux-cc.rul x86_64-linux-cc.rul                            && 
    cd $SOURCE_DIRECTORY 
fi                                                                      &&
################################################

if  [  "$CVS"  ==  "y"  ];  then ./autogen.sh ; fi                      &&

sed -i 's:/usr/src/linux/include::'  scsilib/DEFAULTS/Defaults.linux    &&
sed -i 's/xdao=xdao/xdao=no/'  configure                                &&
sed -i 's:#include <linux/sysctl.h>::'  dao/dao.cc                      &&

default_build
