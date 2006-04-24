(
  make    &&

  install -m 755 graphchk    /usr/bin  &&
  install -m 755 kmetis      /usr/bin  &&
  install -m 755 mesh2dual   /usr/bin  &&
  install -m 755 mesh2nodal  /usr/bin  &&
  install -m 755 oemetis     /usr/bin  &&
  install -m 755 onmetis     /usr/bin  &&
  install -m 755 partdmesh   /usr/bin  &&
  install -m 755 partnmesh   /usr/bin  &&
  install -m 755 pmetis      /usr/bin  &&

  install -d /usr/include/metis
  for file in `ls -1 Lib/*.h` ; do
    install -m 644 $file /usr/include/metis
  done

  install -m 644 libmetis.a  /usr/lib        &&

  install -d /usr/doc/metis  &&
  install -m 644 Doc/manual.ps /usr/doc/metis

) > $C_FIFO 2>&1
