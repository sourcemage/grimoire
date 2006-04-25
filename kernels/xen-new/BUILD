# Xen's makefile provides a set of published targets which are reliable and 
# several internal ones which tend to change.  This BUILD just uses the
# reliable ones.  The old xen spells tried to get clever here and this is why
# they broke.
# - make world currently does clean, kdelete, and dist
# - dist currently does xen, tools, kernels, and docs
# - kernels downloads kernel sources, patches them, and builds them for xen
# Getting a custom kernel config in place this way means doing make world (or 
# dist) once, configuring the kernels, and then doing make dist (or kernels) 
# again.

cd  ${XEN_SOURCE_DIRECTORY}  &&

unset CFLAGS  &&
make world    &&

if  [  "${XEN_CONFIGURE_DOM0}"  ==  "y"  ]  ;  then
  cd  linux-${XEN_KVERSION}-xen0  &&
  make  ARCH=xen  menuconfig  >/dev/tty 2>/dev/tty </dev/tty  &&
  cd ..
fi  &&

if  [  "${XEN_CONFIGURE_DOMU}"  ==  "y"  ]  ;  then
  cd  linux-${XEN_KVERSION}-xenU  &&
  make  ARCH=xen  menuconfig  >/dev/tty 2>/dev/tty </dev/tty  &&
  cd ..
fi  &&

make dist
