(

  make all                   &&
  prepare_install            &&
  cp bfi bfc /usr/bin        &&
  BFDIR=/usr/share/brainfuck &&
  mkdir -p $BFDIR            &&
  cp *.b $BFDIR

) > $C_FIFO 2>&1
