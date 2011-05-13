if [[ $OOLITE_DEVEL == "y" ]]; then
  . ${INSTALL_ROOT}/usr/share/GNUstep/Makefiles/GNUstep.sh &&
  make -f Makefile release || return 1
else
  default_build debug=no || return 1
fi
