(
  make                                               &&
  prepare_install                                    &&
  cp png2ico /usr/bin                                &&
  chmod +x /usr/bin/png2ico
  if ! [ -e /usr/share/man/man1/png2ico.1 ]; then     
     cp ./doc/png2ico.1 /usr/share/man/man1/  
  fi

) > $C_FIFO 2>&1
