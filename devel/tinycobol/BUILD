(
  OPT_SEDITS="s/-Wall/-Wall $CFLAGS/"

  sedit  "$OPT_SEDITS"     cobpp/Makefile.in
  sedit  "$OPT_SEDITS"  compiler/Makefile.in
  sedit  "$OPT_SEDITS"       lib/Makefile.in

  ./configure  --build=$BUILD      \
               --prefix=/usr       \
               --enable-debug-all  \
               $OPTS               &&
  make                             &&
  prepare_install                  &&
  make    install

) > $C_FIFO 2>&1
