sedit  "s/DEST_PATH\ \=\ \/usr\/local/DEST_PATH\ \=\ \/usr/"                                 Makefile      &&
sedit  "s/DEST_PATH\ \=\ \/usr\/local/DEST_PATH\ \=\ \/usr/"                                 src/Makefile  &&
sedit  "s/CFLAGS\ \=\ \-ggdb\ \-Wall\ \-O2/CFLAGS\ \=\ \-ggdb\ $CFLAGS/"                     src/Makefile  &&
sedit  "s/LIBFLAGS\ \=\ \-ggdb\ \-Wall\ \-O2 \-fPIC/LIBFLAGS\ \=\ \-ggdb\ \-fPIC\ $CFLAGS/"  src/Makefile  &&
make

