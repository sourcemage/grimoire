(

sed -e s/'$(DIET)'//g -i Makefile &&
sed -e s/'dev->pcidom = p->domain;'// -i pci.c &&

make && 
make install &&
make install-program 

) > $C_FIFO 2>&1
