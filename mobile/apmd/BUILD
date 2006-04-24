sedit  "s/-O /$CFLAGS /"  Makefile  &&
sedit  "s/\/man/\/share\/man/" Makefile &&

#
# If xfree86 is not installed, do not compile xapm (as it would 
# fail and break spell), Bug #491
#
if  [  !  "$APMD_USE_X"  =  "y"  ];  then
  sedit  "s/EXES=apm apmd xapm apmsleep/EXES=apm apmd apmsleep/"     Makefile  &&
  sedit  's/$(LT_INSTALL)        xapm        $(DESTDIR)$(BINDIR)//'  Makefile
fi  &&

make
