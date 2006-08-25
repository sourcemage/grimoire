sedit "s:/usr/local:${INSTALL_ROOT}/usr:" Makefile.linux  &&
# dependent apps should be able to link without specifying -lpthread
sedit 's:gcc -shared -o:gcc -shared $(LIBS) -o:' Makefile.linux &&
make -f Makefile.linux sharedlib
