if  [[  $CC  ]];  then
  sedit  "s:CC= cc:CC= $CC:"  $SOURCE_DIRECTORY/Makefile
fi  &&

sedit  "s:CFLAGS= -g -DUSE_SEMAPHORE \$(PIC):CFLAGS= -g $CFLAGS -DUSE_SEMAPHORE \$(PIC):"  $SOURCE_DIRECTORY/Makefile  &&
  
make
