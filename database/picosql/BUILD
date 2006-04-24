  PREFIX=${INSTALL_ROOT}/usr/share/picosql	&&
# insert CFLAGS into all subdir makefiles
# remove -static from link stage
  local L                       &&
  for L  in  `ls -d *` ;  do
    if [[ -f $L/Makefile ]] ; then
      sedit "s/CFLAGS=-O/CFLAGS+=/;s/-static//"  $L/Makefile;
    fi
  done                      &&
  make
