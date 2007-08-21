   if [ "$CVS" == "y" ]; then
          patch -p0 < $SCRIPT_DIRECTORY/fixinstall.diff &&
          ./gen
  fi  &&
  LDFLAGS="$LDFLAGS -L/usr/X11R6/lib"          &&

  ./configure  --prefix=${INSTALL_ROOT}/usr        \
               --sysconfdir=${INSTALL_ROOT}/etc    \
               --localstatedir=${INSTALL_ROOT}/var \
	       $OPTS                &&
  make
