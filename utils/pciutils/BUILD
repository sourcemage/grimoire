sedit  "s:/local::" Makefile                                  &&
sedit  "s:PREFIX=/usr:PREFIX=${INSTALL_ROOT}/usr:"  Makefile  &&
patch -p1 < $SCRIPT_DIRECTORY/pciutils-devicetype.patch &&

cd  lib                              &&
./configure $INSTALL_ROOT/usr/share  &&
cd  ..                               &&
make_single                          &&
make
