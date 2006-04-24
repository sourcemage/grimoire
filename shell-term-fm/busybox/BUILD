sedit  "s:OPTIMIZATION=\${call check_gcc,-Os,-O2}:OPTIMIZATION=${CFLAGS}:" Rules.mak  &&
sedit  "s:OPTIMIZATION+=-march=i386::"  Rules.mak                                     &&

make  dep  &&
make
