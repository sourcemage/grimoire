rm Makefile* &&
qmake	&&
make clean	&&
patch -p0 < $SCRIPT_DIRECTORY/qdialog.patch &&
make kaddressbook/Makefile	&&
cp $SCRIPT_DIRECTORY/Makefile desktop/	&&
make		&&
cd desktop	&&
make		&&
cd ..
