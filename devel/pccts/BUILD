(
for i in $(grep -rl varargs.h .)
	do sedit "s/varargs.h/stdarg.h/g" $i
done &&

  sedit  "s:\#COPT=-O2:COPT=$CFLAGS:"  makefile    &&
  make                                             &&
  prepare_install                                  &&
  install  -m  700 bin/antlr  /usr/bin             &&
  install  -m  700 bin/dlg    /usr/bin             &&
  install  -m  700 bin/genmk  /usr/bin             &&
  install  -m  700 bin/sor    /usr/bin             &&
  mkdir                       /usr/include/$SPELL  &&
  cp       h/*                /usr/include/$SPELL

) > $C_FIFO 2>&1
