sedit  "s:/local::" Makefile                                  &&
sedit  "s:PREFIX=/usr:PREFIX=${INSTALL_ROOT}/usr:"  Makefile  &&

cd  lib                              &&
./configure $INSTALL_ROOT/usr/share  &&
cd  ..                               &&
make_single                          &&
make
