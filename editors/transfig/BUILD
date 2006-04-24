  sed -i "s|/local||" fig2dev/Imakefile &&

  if [ "$DEVEL" == "n" ];then
    patch -p0 < $SCRIPT_DIRECTORY/transfig.patch  
  fi                                            &&
  xmkmf                                         &&
  make Makefiles                                &&
  make                                          
