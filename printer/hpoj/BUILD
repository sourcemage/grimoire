./configure  --prefix=/usr                         \
             --sysconfdir=/etc                     \
             --localstatedir=/var                  \
             $OPTS                                 &&

patch  -p0  <  ${SCRIPT_DIRECTORY}/Makefile.patch  &&
sedit  "s:/share/doc/hpoj:/doc/hpoj:g"   Makefile  &&

make_single                                        &&
make                                               &&
make_normal
