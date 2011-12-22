if [[ $BLACKBOX_BRANCH == scm ]]; then
  aclocal &&
  ./mk.sh
fi                                     &&
sedit '30a\
#include <cassert>\' src/Window.cc     &&
export 	LC_ALL=en_US	               &&
./configure  --build=$BUILD            \
             --prefix=${INSTALL_ROOT}/usr             \
             --sysconfdir=${INSTALL_ROOT}/etc         \
             --infodir=${INSTALL_ROOT}/usr/share/info \
             --mandir=${INSTALL_ROOT}/usr/share/man   \
             --localstatedir=${INSTALL_ROOT}/var      \
             $OPTS                                    &&
make
