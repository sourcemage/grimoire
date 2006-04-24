(
  cp INSTALL/make.inc.LINUX make.inc          &&

  make install       &&
  make blaslib       &&
  make lapacklib     &&
  make tmglib        &&

  install -m 644 blas_LINUX.a    /usr/lib/libblas.a  
  install -m 644 lapack_LINUX.a  /usr/lib/liblapack.a 
  install -m 644 tmglib_LINUX.a  /usr/lib/libtmglib.a  

  install -d -m 755 /usr/man/manl
  for file in `ls -1 man/manl/*` ; do
    install -m 644 $file /usr/man/manl
  done

  for file in `ls -1 blas/man/manl/*` ; do
    install -m 644 $file /usr/man/manl
  done

  gcc -o equivalence equivalence.c       
  install -m 755 equivalence  /usr/bin   

) > $C_FIFO 2>&1
