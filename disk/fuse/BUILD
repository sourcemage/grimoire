if [[ $CVS == y ]]; then
  OPTS="$OPTS --disable-mtab"
fi &&

default_build_configure &&

# patching generated Makefile to disable installation of init.d script
sedit 's?\$(mkdir_p) \$(DESTDIR)\$(INIT_D_PATH)?#\$(mkdir_p) \$(DESTDIR)\$(INIT_D_PATH)?' util/Makefile &&
sedit 's?\$(INSTALL_PROGRAM) \$(srcdir)/init_script \$(DESTDIR)\$(INIT_D_PATH)/fuse?#\$(INSTALL_PROGRAM) \$(srcdir)/init_script \$(DESTDIR)\$(INIT_D_PATH)/fuse?' util/Makefile &&

default_build_make
