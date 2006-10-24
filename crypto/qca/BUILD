sedit "s:include<q:include<qt/q:g" configure           &&
sedit 's:INSTALL_ROOT:MY_INSTALL_ROOT:' qcextra        &&
./configure --prefix=${INSTALL_ROOT}/usr $OPTS         &&
sedit 's:-I.ui:-I${QTDIR}/include/qt -I.ui:' Makefile  &&
sedit 's:INSTALL_ROOT:MY_INSTALL_ROOT:g' Makefile      &&
sedit 's:../../lib/$(T:/usr/lib/$(T:g' Makefile        &&
sedit 's:../../include:/usr/include:g' Makefile        &&
make
