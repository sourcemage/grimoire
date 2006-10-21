(
  # fix for undefined reference to `__gxx_personality_v0'
  sedit 's:-o vserver-stat:& -lstdc++:' Makefile &&
  sedit 's:-o vreboot:& -lstdc++:' Makefile &&
  sedit 's:-o listdevip:& -lstdc++:' Makefile &&
  sedit 's:-o fakerunlevel:& -lstdc++:' Makefile &&
  
  make			&&
  prepare_install	&&
  make  install
  
) > $C_FIFO 2>&1
