echo  "/usr/bin"                                 >  conf-bin     &&
echo  "/usr/lib/bglibs/lib"                      >  conf-bglibs  &&
echo  "/usr/lib/bglibs/include"                  >  conf-bgincs  &&
echo  "gcc ${CFLAGS} -I/usr/lib/bglibs/include"  >  conf-cc      &&
echo  "gcc -s -L/usr/lib/bglibs/lib"             >  conf-ld      &&

make  programs
