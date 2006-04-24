  # Fix for Sorcery not having a 'man' group
  sedit  's/--group=man/--group=root/g'  doc/Makefile.in  &&

  # Fix for yard installing configurations into /lib/yard
  zcat ${SCRIPT_DIRECTORY}/Makefile.in.patch.gz  |  patch  -p0

  ./configure  --prefix=/  &&
  make
