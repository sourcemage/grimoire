  sedit "s/else SHAPE/else/g" oneko.c                            &&
  sedit "s/endif SHAPE/endif/g" oneko.c                          &&
  sedit "s/\/\*\*\/\# Cannot compile in using Gcc//g" Imakefile  &&
  xmkmf -a                                                       &&
  echo  "Making oneko"                                           &&
  make
