(
I_DIR=${INSTALL_ROOT}/usr/share/games/$SPELL             &&
  ./configure  --build=$BUILD                            \
               --prefix=${INSTALL_ROOT}/usr/share/games  \
               --bindir=${INSTALL_ROOT}/usr/share/games  \
               $OPTS                                     &&
  make                                                   &&
  prepare_install                                        &&
  make    install
echo -e "#!/bin/sh \n
# Needed to make symlinks/shortcuts work. \n
# the binaries must run with correct working directory \n
cd "${I_DIR}" \n ./tuxtype \$* \n exit \$?" > ttype &&
  mkdir -p ${INSTALL_ROOT}/usr/games                &&
install ttype ${INSTALL_ROOT}/usr/games/tuxtype

) > $C_FIFO 2>&1
