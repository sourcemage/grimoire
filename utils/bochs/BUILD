OPTS="$OPTS --with-x11                    \
            --enable-cdrom=yes            \
	    --enable-vbe                  \
	    --enable-pci                  \
	    --enable-usb                  \
	    --enable-new-pit              \
	    --enable-cpu-level=6          \
	    --enable-x86-64               \
            --enable-vme                  \
            --enable-fpu                  \
	    --enable-mmx                  \
	    --enable-3dnow                \
	    --enable-sse=4                \
	    --enable-disasm               \
	    --enable-idle-hack            \
            --enable-all-optimizations    \
            --enable-repeat-speedups      \
            --enable-icache               \
	    --enable-plugins              \
	    --enable-save-restore         \
            --enable-compressed-hd        \
	    --enable-pnic                 \
            --enable-ne2000               \
	    --disable-docbook             \
            $RFB $SB16 $TERM $APIC $SMP $IPS"  &&

CFLAGS="$CFLAGS" CXXFLAGS="$CFLAGS" default_build
