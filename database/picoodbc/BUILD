# insert CFLAGS into all subdir makefiles
# and remove references to /usr/local
  local L       &&
  for L  in  `ls -d *` ;  do
    if [[ -f $L/Makefile ]] ; then
      sedit "s/CFLAGS=/CFLAGS+=/;s#/local##" $L/Makefile;
    fi
  done			
  make
