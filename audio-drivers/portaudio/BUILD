(

  sedit "s:/usr/local:/usr:" Makefile.linux  &&

  prepare_install                     &&
  make -f Makefile.linux              &&
  make -f Makefile.linux libinstall   &&
  cp  pa_common/portaudio.h           \
      /usr/include

) > $C_FIFO 2>&1
