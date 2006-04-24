cp $SCRIPT_DIRECTORY/Makefile .
(

  echo "" >> mix.h                   &&
  make                               &&
  prepare_install                    &&
  make    install

) > $C_FIFO 2>&1

