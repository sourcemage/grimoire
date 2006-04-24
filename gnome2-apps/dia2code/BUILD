./configure  --build=$BUILD                          \
             --prefix=${INSTALL_ROOT}/usr            \
             --sysconfdir=${INSTALL_ROOT}/etc        \
             --localstatedir=${INSTALL_ROOT}/var     \
             $OPTS                                   &&

sedit 's_^#include <\(parser\|tree\).h>$_#include <libxml/\1.h>_' \
       dia2code/dia2code.h                           &&

  make                                               
