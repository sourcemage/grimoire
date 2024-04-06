./configure  --prefix=/usr $OPTS         \
         --sysconfdir=/etc               \
      --localstatedir=/var               \
             --enable-fpu                \
             --with-x11                  \
             --enable-ne2000             \
             --enable-cdrom=yes          \
             --enable-icache             \
             $RFB                        \
             $SB16                       \
             $SMP                        \
             $TERM                       \
             $SVGA                       \
             $WX                         \
             $SDL                        \
             $APIC                       \
             --enable-all-optimizations  &&

if [ "$IPS" == "y" ]; then
  message "Editing config.h"  &&
  sedit "s/#define BX_SHOW_IPS         0/#define BX_SHOW_IPS         1/" ./config.h 
  cat ./config.h
fi  &&

make
