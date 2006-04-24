(
  # fix for undefined reference to `__gxx_personality_v0'
  sedit 's:-o vserver-stat:-o vserver-stat -lstdc++:'  Makefile	&&

  make			&&
  prepare_install	&&
  make  install
  
) > $C_FIFO 2>&1
