sedit  "s/gmake/make/"       Make/instexamplesrc  &&
sedit  "s/-O2/\"$CFLAGS\"/"  Make/makedefs        &&
for  i  in  $(grep  -rl  YieldCurrentThread  .)
do
  sedit  "s/YieldCurrentThread/CurrentThread/"  $i
done                                              &&
make  opt  GIF_LIBS="-lungif"
