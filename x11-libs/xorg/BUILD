invoke_gcc  &&
message  "${MESSAGE_COLOR}Building X.org takes a very long time${DEFAULT_COLOR}"  &&

# Do not remove PIC switches from compiler flags!

if  (echo $CFLAGS | grep -q -- "-Os"); then
  export CFLAGS="-O2 ${CFLAGS//-Os/}"
fi  &&

if [ "$X_LATEST" == "n" ] ; then
  patch -p1 < $SCRIPT_DIRECTORY/shared-Xau.patch 
fi &&

# don't install to /usr/X11R6/lib64 :) (malleus lib64arum)
for i in \
    ./config/cf/linux.cf                                             \
    ./extras/Mesa/configs/linux-x86-64                               \
    ./extras/Mesa/configs/linux-x86-64-static                        \
    ./extras/Mesa/configs/linux-dri-x86-64                           \
    ./programs/Xserver/hw/xfree86/etc/bindist/Linux-amd64/mod-list   \
    ./programs/Xserver/hw/xfree86/etc/bindist/Linux-amd64/prog-excl  \
    ./programs/Xserver/hw/xfree86/etc/bindist/Linux-amd64/prog-list  \
    ./programs/Xserver/hw/xfree86/etc/bindist/Linux-amd64/bin-list
  do
    sedit 's/lib64/lib/g' "$i"
done &&

make  World
