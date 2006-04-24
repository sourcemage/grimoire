invoke_gcc
   if [ "$CVS" == "y" ]; then
          patch -p0 < $SCRIPT_DIRECTORY/fixinstall.diff &&
          ./gen
  fi  &&
#  if [ "$CVS" == "yes" ]; then 
#	export MAKE_NJOBS=1    &&
#	patch -p0 < $SCRIPT_DIRECTORY/fixinstall.diff &&
#	./gen 
#  fi &&
  ./configure  --prefix=${INSTALL_ROOT}/usr        \
               --sysconfdir=${INSTALL_ROOT}/etc    \
               --localstatedir=${INSTALL_ROOT}/var \
               --enable-xft      \
	       $OPTS                &&
  make
