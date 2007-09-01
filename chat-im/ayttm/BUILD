   if [ "$CVS" == "y" ]; then
          patch -p0 < $SCRIPT_DIRECTORY/fixinstall.diff &&
          ./gen
  fi  &&

  ./configure  --prefix=${INSTALL_ROOT}/usr        \
               --sysconfdir=${INSTALL_ROOT}/etc    \
               --localstatedir=${INSTALL_ROOT}/var \
	       $OPTS                &&
  make
