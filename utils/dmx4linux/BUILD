INCLUDE=/lib/modules/`uname -r`/build/include
MODULES=/lib/modules/`uname -r`/misc

echo  -e  "$DUMMY\n$PARPORT\n$ISA\n$USB\n$PCMCIA\n$I2C\n"     \
     "$X\n$CURSES\n$XMMS\n$PCMCIACONFIG$PCMCIABIN$INCLUDE\n"  \
     "$CFLAGS\n$LDFLAGS\n/usr/include\n$MODULES\n"            \
     "/usr/bin\n/usr/lib\n/usr/share/man\n"                   &&

echo  -e  "$DUMMY\n$PARPORT\n$ISA\n$USB\n$PCMCIA\n$I2C\n"     \
     "$X\n$CURSES\n$XMMS\n$PCMCIACONFIG$PCMCIABIN$INCLUDE\n"  \
     "$CFLAGS\n$LDFLAGS\n/usr/include\n$MODULES\n"            \
     "/usr/bin\n/usr/lib\n/usr/share/man\n"                   |
     default_build
