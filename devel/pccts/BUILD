for i in $(grep -rl varargs.h .)
	do sedit "s/varargs.h/stdarg.h/g" $i
done &&

  sedit  "s:\#COPT=-O2:COPT=$CFLAGS:"  makefile    &&
  make
