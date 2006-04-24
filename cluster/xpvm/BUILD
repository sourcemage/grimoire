(
  export XPVM_HOME=/usr/share/xpvm            &&
  export XPVM_SRC=$SOURCE_DIRECTORY           &&
  export XPVM_ROOT=$XPVM_SRC                  &&
  export PVM_ROOT=/usr/share/pvm              &&
  export PVM_ARCH=`pvmgetarch`                &&
  patch -p1 < $SCRIPT_DIRECTORY/xpvm-1.2.5.patch &&
  make                                        &&
  install -d ${XPVM_HOME}/lib/${PVM_ARCH}     &&
  install -m 755 ${XPVM_SRC}/src/${PVM_ARCH}/xpvm ${XPVM_HOME}/lib/${PVM_ARCH} &&
  for file in ${XPVM_SRC}/*.tcl; do           \
    install -m 644 $file ${XPVM_HOME};        \
  done                                        &&
  install -d ${XPVM_HOME}/xbm                 &&
  install -m 644 ${XPVM_SRC}/src/xbm/*   ${XPVM_HOME}/xbm   &&
  install -d ${XPVM_HOME}/help                &&
  install -m 644 ${XPVM_SRC}/src/help/*  ${XPVM_HOME}/help
 
) > $C_FIFO 2>&1

