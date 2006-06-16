./configure --prefix=${INSTALL_ROOT}/usr &&

sedit "s:-DLIBSVN::g" Makefile                           &&
sedit "s:-I/usr/include/subversion-1::g" Makefile        &&
sedit "s:-lsvn_client-1 -lapr-0 -laprutil-0::g" Makefile &&

make
