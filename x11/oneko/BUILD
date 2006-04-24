(

  sedit "s/else SHAPE/else/g" oneko.c                            &&
  sedit "s/endif SHAPE/endif/g" oneko.c                          &&
  sedit "s/\/\*\*\/\# Cannot compile in using Gcc//g" Imakefile  &&
  xmkmf -a                                                       &&
  echo  "Making oneko"                                           &&
  make                                                           &&
  prepare_install                                                &&
  cp -vf oneko.man /usr/man/man8/oneko.8                         &&
  cp -vf oneko /usr/X11R6/bin                                    &&
  chmod +x /usr/X11R6/bin/oneko

) > $C_FIFO 2>&1
