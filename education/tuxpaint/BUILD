if [[ "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" ]];  then
  sedit  "s:CFLAGS=-g:& $CFLAGS:" magic/Makefile
fi  &&

sedit "s/\/usr\/local/\/usr/g" Makefile           &&
sedit "s/OPTFLAGS=-O2/CFLAGS=$CFLAGS/g" Makefile  &&
make
