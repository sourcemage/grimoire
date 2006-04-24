MUNAME=`uname -m`
if  [ $MUNAME = 'x86_64' ]
then
  sedit  "s/^CFLAGS_SHLIB =/CFLAGS_SHLIB = -fPIC/" Makefile.config.in
fi &&
echo  -e  "\ngnu\nregular\nshared\ny\n\n\n\n\n\n\n\n\n\n\n\n"  |
#  Ignores  $OPTS
# to get our OPTS and CFLAGS, etc we'll need to sed Makefile.config.in
./configure                        &&
make_single                        &&
make                               &&
if [ -e /tmp/netpbm ]; then
   rm -rf /tmp/netpbm              
fi                                 &&
make  package  pkgdir=/tmp/netpbm  &&
make_normal
