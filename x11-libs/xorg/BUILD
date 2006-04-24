# Do not remove PIC switches from compiler flags!

if  (echo $CFLAGS | grep -q -- "-Os"); then
  export CFLAGS="-O2 ${CFLAGS//-Os/}"
fi  &&

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
