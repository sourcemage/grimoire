OPTS="$OPTS --enable-all-optimizations    \
            --enable-fpu                  \
            --with-x11                    \
            --enable-ne2000               \
            --enable-cdrom=yes            \
            --enable-icache               \
            --enable-repeat-speedups      \
            --enable-config-interface     \
            $RFB $SB16 $SMP $TERM $APIC"

if  [  "$IPS"  =  "y"  ]  ;  then
  sedit  's/\(#define BX_SHOW_IPS\)  *0/\1 1/'  config.h.in
fi  &&

default_build
