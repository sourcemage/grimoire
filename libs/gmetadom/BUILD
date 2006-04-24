#gcc3.3 hack
if [[ $(gcc -dumpversion)   == 3.3* ]] ; then
sedit '27a\
\#include \<assert.h\>\' src/gdome_cpp_smart/test/main.cc
fi  &&
default_build
