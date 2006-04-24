  PREFIX=${INSTALL_ROOT}/usr/share/picosql	&&
# insert CFLAGS into all subdir makefiles
  local L                       &&
  for L  in  `ls -d *` ;  do
    if [[ -f $L/Makefile ]] ; then
      sedit \
"s/CFLAGS=-O/CFLAGS+=-D_MSC_VER/;s/OFLAGS=-O/OFLAGS=$CFLAGS/" \
		$L/Makefile;
    fi
  done                      &&
  make
